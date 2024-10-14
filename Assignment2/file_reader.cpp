#include <iostream>
#include <fstream>

int main() {
    // Открытие бинарного файла для чтения std::ifstream inputFile("input.bin", std::ios::binary);
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    // Определение размера файла std::streamsize fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    // Выделение памяти под массив
    char* buffer = new char[fileSize];

    // Считывание файла в массив
    if (!inputFile.read(buffer, fileSize)) {
        std::cerr << "Ошибка при чтении файла." << std::endl;
        delete[] buffer;
        return 1;
    }
    inputFile.close();

    // Разворот массива
    for (std::streamsize i = 0; i < fileSize / 2; ++i) {
        std::swap(buffer[i], buffer[fileSize - i - 1]);
    }

    // Запись в новый файл std::ofstream outputFile("output.bin", std::ios::binary);
    if (!outputFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        delete[] buffer;
        return 1;
    }

    // Запись массива в файл одной командой
    outputFile.write(buffer, fileSize);
    outputFile.close();

    // Освобождение памяти
    delete[] buffer;

    std::cout << "Файл успешно обработан и записан в output.bin" << std::endl;
    return 0;
}
