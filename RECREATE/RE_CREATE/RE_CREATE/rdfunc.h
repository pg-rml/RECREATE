#pragma once
#include <iostream>
#include <random>

int static rdfunc() {
    // 랜덤 엔진과 분포 설정
    std::random_device rd;
    std::mt19937 gen(rd()); // 메르센 트위스터 엔진을 사용
    std::uniform_int_distribution<int> dist(1, 1000); // 1부터 n 사이의 균일한 분포

    return dist(gen);
}