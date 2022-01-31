#include <algorithm>
#include <iomanip>
#include <iostream>
#include <mysql++.h>
#include <vector>

using namespace std;
using namespace mysqlpp;

typedef vector<size_t> IntVectorType;

static void print_header(IntVectorType& widths, StoreQueryResult& res)
{
    cout << "  |" << setfill(' ');
    for (size_t i = 0; i < res.field_names()->size(); i++) {
        cout << " " << setw(widths.at(i)) << res.field_name(int(i)) << " |";
    }
    cout << endl;
}

static void print_row(IntVectorType& widths, Row& row)
{
    cout << "  |" << setfill(' ');
    for (size_t i = 0; i < row.size(); ++i) {
        cout << " " << setw(widths.at(i)) << row[int(i)] << " |";
    }
    cout << endl;
}

static void print_row_separator(IntVectorType& widths)
{
    cout << "  +" << setfill('-');
    for (size_t i = 0; i < widths.size(); i++) {
        cout << "-" << setw(widths.at(i)) << '-' << "-+";
    }
    cout << endl;
}

static void print_result(StoreQueryResult& res, int index)
{
    // Show how many rows are in result, if any
    StoreQueryResult::size_type num_results = res.size();
    if (res && (num_results > 0)) {
        cout << "Result set " << index << " has " << num_results << " row"
             << (num_results == 1 ? "" : "s") << ':' << endl;
    } else {
        cout << "Result set " << index << " is empty." << endl;
        return;
    }

    // Figure out the widths of the result set's columns
    IntVectorType widths;
    size_t size = res.num_fields();
    for (size_t i = 0; i < size; i++) {
        widths.push_back(max(res.field(i).max_length(), res.field_name(i).size()));
    }

    // Print result set header
    print_row_separator(widths);
    print_header(widths, res);
    print_row_separator(widths);

    // Display the result set contents
    for (StoreQueryResult::size_type i = 0; i < num_results; ++i) {
        print_row(widths, res[i]);
    }

    // Print result set footer
    print_row_separator(widths);
}

static void print_multiple_results(Query& query)
{
    // Execute query and print all result sets
    StoreQueryResult res = query.store();
    print_result(res, 0);
    for (int i = 1; query.more_results(); ++i) {
        res = query.store_next();
        print_result(res, i);
    }
}

int main(int argc, char* argv[])
{
    // Connect to the sample database.
    mysqlpp::Connection conn("sklep_rtv", "db", "root", "root", 3306);
    conn.set_option(new MultiStatementsOption(true));

    Query query = conn.query();
    std::string description;
    std::getline(std::cin, description);
    query << "select opis, cena from Produkty WHERE opis LIKE '% " << description << "%';";
    print_multiple_results(query);

    return 0;
}
