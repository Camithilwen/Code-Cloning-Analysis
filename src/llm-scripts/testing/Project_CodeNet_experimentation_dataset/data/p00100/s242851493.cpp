#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

struct EmployeeSale {
	long employee_number;
	long long sales;
};

int main()
{
	int data_count = 0;
	while (std::cin >> data_count) {
		if (data_count == 0) {
			break;
		}
		std::vector<EmployeeSale> sales_per_employee;
		for (int i = 0; i < data_count; ++i) {
			long employee_number = 0;
			long unit_price = 0;
			long quantity = 0;
			if (std::cin >> employee_number >> unit_price >> quantity) {
				long long each_sales = static_cast<long long>(unit_price) * quantity;
				auto it = std::find_if(
					sales_per_employee.begin(),
					sales_per_employee.end(),
					[=](EmployeeSale const& sale){ return sale.employee_number == employee_number; });
				if (it != sales_per_employee.end()) {
					it->sales += each_sales;
				} else {
					EmployeeSale sales = { employee_number, each_sales };
					sales_per_employee.push_back(sales);
				}
			}
		}

		std::vector<EmployeeSale> sales_achieved;
		std::copy_if(
			sales_per_employee.begin(),
			sales_per_employee.end(),
			std::back_inserter(sales_achieved),
			[](EmployeeSale const& sale){ return sale.sales >= 1000000; });
		if (!sales_achieved.empty()) {
			std::for_each(
				sales_achieved.begin(),
				sales_achieved.end(),
				[](EmployeeSale const& sale){ std::cout << sale.employee_number << std::endl; });
		} else {
			std::cout << "NA\n";
		}
	}

	return 0;
}