#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int is_valid(vector< string > batch) {
  static const vector< string > required_fields = {
    "byr:", "iyr:", "eyr:", "hgt:",
    "hcl:", "ecl:", "pid:"
  };

  map<string, bool> fields;
  for (const auto& line : batch) {
    for (const auto& rf : required_fields) {
      if (line.find( rf ) != string::npos) {
        fields[ rf ] = true;
      }
    }
  }

  return (required_fields.size() == fields.size());
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


