//
// Created by krage56 on 29.03.2020.
//
using namespace std;
#include "polinominal.h"
#include "Field_Z.h"

void return_in_pos(fstream *file, bool pos){
    file->clear();
    pos ? file->seekg(0, ios_base::beg): file->seekg(0, ios_base::end);
}
bool is_empty_file(fstream *file){
    long file_size;
    file->seekg(0, ios::end);
    file_size = file->tellg();
    return (file_size == 0);
}

bool processing(fstream *file, size_t &N, size_t &p, long &a, vector<vector<Field_Z>> &vec){
    if(!file->is_open()) return false;
    const size_t param_quant = 3;
    return_in_pos(file, true);//Вернуться к началу файла
    char buf[mem_block];
    for(int i = 0; i < param_quant; ++i){
        file->getline(buf, mem_block,i < param_quant - 1 ? ' ': '\n');
        switch (i){
            case 0:{
                p = atoi(buf);
                break;
            }
            case 1:{
                a = atoi(buf);
                break;
            }
            case 2:{
                N = atoi(buf);
                break;
            }
        }
    }

    memset(buf, 0, sizeof(char) * mem_block);
    vector<Field_Z> tmp_vec(2);
    for(int i = 0; i < N; ++i){
        for(short j = 0; j < 2; ++j){
            file->getline(buf, mem_block,j ? '\n': ' ');
            tmp_vec[j] = Field_Z(p, atoi(buf));
        }
        vec.push_back(tmp_vec);
    }
    return true;
}

Field_Z calculation(std::vector<vector<Field_Z>> &data, size_t base, long point_x) {
    Field_Z lagrange_pol(base, 0);
    Field_Z basics_pol(base, 0);
    Field_Z x(base, point_x);
    for (size_t i = 0; i < data.size(); i++){
        basics_pol = 1;
        for (size_t j = 0; j < data.size(); j++){
            if (j == i) continue;
            basics_pol *= (x - data[j][0])/(data[i][0] - data[j][0]);
        }
        lagrange_pol += basics_pol*data[i][1];
    }
    lagrange_pol.normalize();
    /*ofstream answer;
    answer.open("./answer.txt");
    answer << lagrange_pol << "\n";
    answer.close();*/
	return lagrange_pol;
}


