//https://contest.yandex.ru/contest/27844/problems/F/

#include "funcs.h"
#include <bits/stdc++.h>

//! @brief Index of last true. If everything is false return 0
template<typename F1, typename F2>
unsigned long long binSearchLowerBound(F1 valueGenerate,
                           F2 valueCheck,
                                       unsigned long long left, unsigned long long right){
    while (left<right){
        unsigned long long cur = (left + right + 1)/2;
        auto value = valueGenerate(cur);
        if(valueCheck(value)){
            left = cur;
        } else {
            right = cur-1;
        }
    }
    return right;
}

//! @brief Number of copies when both printers are running
unsigned long long copies(
        unsigned long long x,
        unsigned long long y,
        unsigned long long time
        ){
    auto xCopies = time/x;
    auto yCopies = time/y;
    return xCopies + yCopies;
}

void parseFile(std::istream & input, std::ostream & output){

    unsigned long long N, x, y;
    input >> N >> x >> y;
    unsigned long long t1 = std::min(x,y);
    if(N==1){
        output << t1;
        return;
    }
    --N;
    unsigned long long left = 0, right = std::max(x,y)*N;
    auto time = binSearchLowerBound(
            [](unsigned long long d){return d;},
                [&x, &y, &N](unsigned long long time){
                    return copies(x,y,time)<N;
                },
                    left, right);
    if (copies(x,y,time)<N)++time;
    output << time + t1;
}
