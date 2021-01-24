#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include <set>

using namespace std;

int is_valid(vector< string > batch) {
  set< string > required_fields = {
    "byr", "iyr", "eyr", "hgt",
    "hcl", "ecl", "pid"
  };
  set< string> fields;
  string token;
  bool all = true;
  for (const auto& line : batch) {
    istringstream tokens( line );
    while ( tokens >> token ) {
      replace( token.begin(), token.end(), ':', ' ');
      istringstream word( token );
      string field, value;
      int int_value;
      word >> field;
      if (required_fields.find(field) != required_fields.end()) {
        fields.insert( field );
        word >> value;
        sscanf(value.c_str(), "%d", &int_value);
        if (field == "byr") {
          all = (all and int_value >= 1920 && int_value <= 2002);
        } else if (field == "iyr") {
          all = (all and int_value >= 2010 && int_value <= 2020);
        } else if (field == "eyr") {
          all = (all and int_value >= 2020 && int_value <= 2030);
        } else if (field == "hgt") {
          if (value.find( "cm" ) != string::npos)
            all = (all and int_value >= 150 && int_value <= 193);
          else
            all = (all and int_value >= 59 && int_value <= 76);
        } else if (field == "hcl") {
          all = (all and (regex_match (value, regex("#[0-9a-f]{6}") )));
        } else if (field == "ecl") {
          all = (all and (regex_match (value, regex("amb|blu|brn|gry|grn|hzl|oth") )));
        } else if (field == "pid") {
          all = (all and (regex_match (value, regex("[0-9]{9}") )));
        }
        // cout << field << " " << value << " " << all << endl;
      } 
    }
  }

  return (required_fields.size() == fields.size() and all);
}

int main () {
  int valid = 0;
  string line;
  vector <string> batch;

  while (getline(cin, line)) {
    if ( line.size() ) {
      batch.push_back( line );
      continue;
    }
    valid += is_valid( batch );
    batch.clear();
  }
  cout << valid << endl;
  return 0;
}


