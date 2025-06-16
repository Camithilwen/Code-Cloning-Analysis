# /// script
# dependencies = [
#   "pymilvus",
#   "milvus-lite",
#   "prettytable",
# ]
# ///

"""Enhanced Milvus Database Analyzer for Code Repository Embeddings

This script provides comprehensive analysis of Milvus databases containing
code repository embeddings with detailed file tracking and chunk analysis.
"""

from pymilvus import MilvusClient
from prettytable import PrettyTable
from pathlib import Path
import json
from collections import defaultdict, Counter

class MilvusAnalyzer:
    """Enhanced analyzer for Milvus databases with code repository embeddings."""

    def __init__(self, db_path):
        """Initialize the analyzer with database path."""
        self.db_path = db_path
        self.client = None

    def connect(self):
        """Establish connection to Milvus database."""
        try:
            self.client = MilvusClient(uri=self.db_path)
            print(f"✓ Connected to Milvus database: {self.db_path}")
            return True
        except Exception as e:
            print(f"✗ Failed to connect to database: {e}")
            return False

    def get_collections_info(self):
        """Get comprehensive information about all collections."""
        try:
            collections = self.client.list_collections()
            if not collections:
                print("No collections found in the database")
                return None

            print(f"\n📊 Found {len(collections)} collections: {', '.join(sorted(collections))}\n")
            return sorted(collections)
        except Exception as e:
            print(f"Error listing collections: {e}")
            return None

    def analyze_collection_schema(self, collection_name):
        """Analyze collection schema using direct queries."""
        try:
            # Get basic collection statistics
            stats = self.client.get_collection_stats(collection_name)

            # Get a sample record to understand the schema structure
            sample_records = self.client.query(
                collection_name=collection_name,
                filter="id >= 0",
                limit=1,
                output_fields=["*"]  # Get all fields
            )

            schema_info = {
                "total_entities": stats.get('row_count', 0),
                "sample_record": sample_records[0] if sample_records else None,
                "field_names": list(sample_records[0].keys()) if sample_records else [],
                "stats": stats
            }

            return schema_info

        except Exception as e:
            print(f"Error analyzing schema for {collection_name}: {e}")
            return None

    def analyze_file_distribution(self, collection_name):
        """Analyze how files are distributed and chunked in the collection."""
        try:
            print(f"🔍 Analyzing file distribution in {collection_name}...")

            # Get all records with file information
            all_records = self.client.query(
                collection_name=collection_name,
                filter="id >= 0",
                output_fields=["file_path", "file_name", "chunk_index", "total_chunks",
                             "is_complete_file", "file_extension", "file_size"],
                limit=10000  # Adjust based on expected data size
            )

            if not all_records:
                return {"error": "No records found in collection"}

            # Group records by file_path
            files_data = defaultdict(list)
            for record in all_records:
                file_path = record.get('file_path', 'unknown')
                files_data[file_path].append(record)

            # Analyze each file's chunk distribution
            file_analysis = []
            for file_path, chunks in files_data.items():
                chunk_indices = [c.get('chunk_index', 0) for c in chunks]
                total_chunks = chunks[0].get('total_chunks', 0) if chunks else 0

                # Check if chunks form a complete sequence
                expected_indices = set(range(total_chunks)) if total_chunks > 0 else {0}
                actual_indices = set(chunk_indices)
                is_complete = expected_indices == actual_indices

                # Get file metadata
                file_info = chunks[0] if chunks else {}

                file_analysis.append({
                    "file_path": file_path,
                    "file_name": file_info.get('file_name', 'unknown'),
                    "file_extension": file_info.get('file_extension', 'unknown'),
                    "file_size": file_info.get('file_size', 0),
                    "expected_chunks": total_chunks,
                    "actual_chunks": len(chunks),
                    "chunk_indices": sorted(chunk_indices),
                    "missing_chunks": sorted(expected_indices - actual_indices),
                    "extra_chunks": sorted(actual_indices - expected_indices),
                    "is_complete": is_complete,
                    "has_complete_flag": any(c.get('is_complete_file', False) for c in chunks),
                    "chunks_data": chunks
                })

            return {
                "total_files": len(file_analysis),
                "total_chunks": len(all_records),
                "files": file_analysis,
                "complete_files": sum(1 for f in file_analysis if f['is_complete']),
                "incomplete_files": sum(1 for f in file_analysis if not f['is_complete'])
            }

        except Exception as e:
            print(f"Error analyzing file distribution: {e}")
            return {"error": str(e)}

    def get_file_content_sample(self, collection_name, file_path, max_chunks=3):
        """Get content samples from a specific file."""
        try:
            # Get chunks for this specific file
            file_chunks = self.client.query(
                collection_name=collection_name,
                filter=f"file_path == '{file_path}'",
                output_fields=["chunk_index", "content", "total_chunks"],
                limit=max_chunks
            )

            if not file_chunks:
                return None

            # Sort by chunk_index
            file_chunks.sort(key=lambda x: x.get('chunk_index', 0))

            return {
                "chunks_shown": len(file_chunks),
                "total_chunks": file_chunks[0].get('total_chunks', 0) if file_chunks else 0,
                "content_samples": [
                    {
                        "chunk_index": chunk.get('chunk_index', 0),
                        "content_preview": chunk.get('content', '')[:200] + "..." if len(chunk.get('content', '')) > 200 else chunk.get('content', ''),
                        "content_length": len(chunk.get('content', ''))
                    }
                    for chunk in file_chunks
                ]
            }

        except Exception as e:
            print(f"Error getting content sample for {file_path}: {e}")
            return None

    def print_collection_report(self, collection_name):
        """Generate and print comprehensive collection report."""
        print(f"\n{'='*80}")
        print(f"📁 COLLECTION ANALYSIS: {collection_name}")
        print(f"{'='*80}")

        # Get schema information
        schema_info = self.analyze_collection_schema(collection_name)
        if not schema_info:
            print("❌ Failed to analyze collection schema")
            return

        # Print basic statistics
        print(f"\n📈 BASIC STATISTICS")
        print(f"{'─'*40}")
        print(f"Total entities: {schema_info['total_entities']:,}")

        if schema_info['sample_record']:
            print(f"Fields available: {', '.join(schema_info['field_names'])}")

        # Print schema structure
        if schema_info['sample_record']:
            print(f"\n🗂️  SCHEMA STRUCTURE")
            print(f"{'─'*40}")
            schema_table = PrettyTable()
            schema_table.field_names = ["Field Name", "Sample Value", "Type"]

            for field, value in schema_info['sample_record'].items():
                if field == 'vector':
                    sample_val = f"[{len(value)} dimensions]" if isinstance(value, list) else str(value)
                elif field == 'content' and len(str(value)) > 50:
                    sample_val = str(value)[:50] + "..."
                else:
                    sample_val = str(value)

                schema_table.add_row([field, sample_val, type(value).__name__])

            print(schema_table)

        # Analyze file distribution
        file_analysis = self.analyze_file_distribution(collection_name)

        if file_analysis and 'error' not in file_analysis:
            print(f"\n📊 FILE DISTRIBUTION ANALYSIS")
            print(f"{'─'*40}")
            print(f"Total files embedded: {file_analysis['total_files']:,}")
            print(f"Total chunks stored: {file_analysis['total_chunks']:,}")
            print(f"Complete files: {file_analysis['complete_files']:,}")
            print(f"Incomplete files: {file_analysis['incomplete_files']:,}")

            if file_analysis['incomplete_files'] > 0:
                print(f"⚠️  Warning: {file_analysis['incomplete_files']} files have missing chunks!")

            # File summary table
            print(f"\n📋 FILE INVENTORY")
            print(f"{'─'*40}")
            files_table = PrettyTable()
            files_table.field_names = [
                "File Path", "Extension", "Size (bytes)",
                "Expected Chunks", "Actual Chunks", "Complete", "Status"
            ]

            # Sort files by completeness and then by path
            sorted_files = sorted(
                file_analysis['files'],
                key=lambda x: (not x['is_complete'], x['file_path'])
            )

            for file_info in sorted_files:
                status = "✅ Complete" if file_info['is_complete'] else "❌ Incomplete"
                if file_info['missing_chunks']:
                    status += f" (Missing: {file_info['missing_chunks']})"

                # Truncate long paths
                display_path = file_info['file_path']
                if len(display_path) > 40:
                    display_path = "..." + display_path[-37:]

                files_table.add_row([
                    display_path,
                    file_info['file_extension'],
                    f"{file_info['file_size']:,}",
                    file_info['expected_chunks'],
                    file_info['actual_chunks'],
                    "Yes" if file_info['is_complete'] else "No",
                    status
                ])

            print(files_table)

            # Extension analysis
            extensions = Counter(f['file_extension'] for f in file_analysis['files'])
            if extensions:
                print(f"\n🏷️  FILE EXTENSIONS SUMMARY")
                print(f"{'─'*40}")
                ext_table = PrettyTable()
                ext_table.field_names = ["Extension", "Count", "Percentage"]

                total_files = sum(extensions.values())
                for ext, count in extensions.most_common():
                    percentage = (count / total_files) * 100
                    ext_table.add_row([ext, count, f"{percentage:.1f}%"])

                print(ext_table)

            # Show content samples for a few files
            print(f"\n📄 CONTENT SAMPLES")
            print(f"{'─'*40}")
            sample_files = file_analysis['files'][:3]  # Show first 3 files

            for file_info in sample_files:
                print(f"\n📝 File: {file_info['file_path']}")
                content_sample = self.get_file_content_sample(
                    collection_name, file_info['file_path'], max_chunks=2
                )

                if content_sample:
                    print(f"   Chunks: {content_sample['chunks_shown']}/{content_sample['total_chunks']}")
                    for sample in content_sample['content_samples']:
                        print(f"   Chunk {sample['chunk_index']} ({sample['content_length']} chars): {sample['content_preview']}")
                else:
                    print("   ❌ Could not retrieve content sample")

        elif file_analysis and 'error' in file_analysis:
            print(f"❌ Error analyzing files: {file_analysis['error']}")

        print(f"\n{'='*80}")

    def generate_summary_report(self, collections):
        """Generate overall summary report."""
        print(f"\n{'🎯 OVERALL DATABASE SUMMARY':^80}")
        print(f"{'='*80}")

        summary_table = PrettyTable()
        summary_table.field_names = [
            "Collection", "Total Entities", "Estimated Files", "Est. Model Type"
        ]

        total_entities = 0
        total_collections = len(collections)

        for collection_name in collections:
            try:
                stats = self.client.get_collection_stats(collection_name)
                entities = stats.get('row_count', 0)
                total_entities += entities

                # Estimate model type based on collection name
                model_type = "Unknown"
                if "A" in collection_name:
                    model_type = "Jina Embeddings"
                elif "B" in collection_name:
                    model_type = "SFR Embedding"
                elif "C" in collection_name:
                    model_type = "CodeSage"

                # Rough estimate of files (assuming average chunking)
                estimated_files = max(1, entities // 3)  # Rough estimate

                summary_table.add_row([
                    collection_name,
                    f"{entities:,}",
                    f"~{estimated_files:,}",
                    model_type
                ])

            except Exception as e:
                summary_table.add_row([collection_name, "Error", "Error", "Error"])

        print(summary_table)
        print(f"\nTotal Collections: {total_collections}")
        print(f"Total Entities: {total_entities:,}")
        print(f"Database Size: {Path(self.db_path).stat().st_size / (1024*1024):.1f} MB")

    def run_complete_analysis(self):
        """Run complete database analysis."""
        print(f"🚀 MILVUS DATABASE ANALYZER")
        print(f"{'='*80}")
        print(f"Database: {self.db_path}")

        # Verify database exists
        if not Path(self.db_path).exists():
            print(f"❌ Database file not found at {self.db_path}")
            return False

        # Connect to database
        if not self.connect():
            return False

        # Get collections
        collections = self.get_collections_info()
        if not collections:
            return False

        # Generate summary first
        self.generate_summary_report(collections)

        # Analyze each collection in detail
        for collection_name in collections:
            try:
                self.print_collection_report(collection_name)
            except Exception as e:
                print(f"❌ Error analyzing collection {collection_name}: {e}")
                continue

        print(f"\n✅ Analysis Complete!")
        print(f"{'='*80}")
        return True

def main():
    """Main function to run the Milvus database analysis."""
    db_path = "./output/src/embed/data/output/embeddings.db"

    analyzer = MilvusAnalyzer(db_path)
    success = analyzer.run_complete_analysis()

    if not success:
        print("❌ Analysis failed. Please check the error messages above.")
        return 1

    return 0

if __name__ == "__main__":
    exit(main())
