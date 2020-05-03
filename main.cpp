//
// Created by krage56 on 28.03.2020.
//
/*Please write only name of test file without control structures
If the test located one level lower, please write path like lagrange_tests\test.in 
*/
using namespace std;
#include "Field_Z.h"
#include "polinominal.h"

int main(int args, char*argv[]){
    size_t N = 0, p = 0;
    long a = 0;
    char file_name[mem_block];
    cin.getline(file_name, mem_block);
	string path = file_name;
	string full_path = argv[0];
	int index = full_path.find_last_of('\\');
	std::string pathDir = "";
	if (index > -1)
		pathDir = full_path.substr(0, index);
	full_path = pathDir + '\\' + path;
    fstream file;
    file.open(full_path, ios_base::out | ios_base::in);
	vector<vector<Field_Z>> data;//{x, y}
    if(!processing(&file, N, p, a, data)){
        cout << "The program can`t open the file" << endl;
        return 1;
    }
	ofstream answer;
	answer.open(pathDir + "\\answer.out");
	answer << calculation(data, p, a) << "\n";
	answer.close();
    file.close();
    return 0;
}