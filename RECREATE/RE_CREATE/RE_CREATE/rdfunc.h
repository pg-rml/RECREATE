#pragma once
#include <iostream>
#include <random>

int static rdfunc() {
    // ���� ������ ���� ����
    std::random_device rd;
    std::mt19937 gen(rd()); // �޸��� Ʈ������ ������ ���
    std::uniform_int_distribution<int> dist(1, 1000); // 1���� n ������ ������ ����

    return dist(gen);
}