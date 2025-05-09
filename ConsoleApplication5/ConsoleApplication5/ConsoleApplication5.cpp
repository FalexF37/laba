#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

wstring makePlural(wstring word) {
    // Удаляем "(с)" если есть
    if (word.find(L"(с)") != wstring::npos) {
        word = word.substr(0, word.size() - 3);
    }

    // Проверяем исключения
    if (word == L"ребенок") return L"дети";
    if (word == L"бесенок") return L"бесенята";
    if (word == L"звонок") return L"звонки";
    if (word == L"позвонок") return L"позвонки";
    if (word == L"подонок") return L"подонки";
    if (word == L"колонок") return L"колонки";
    if (word == L"жаворонок") return L"жаворонки";
    if (word == L"бочонок") return L"бочонки";

    // Проверяем окончания
    if (word.size() < 4) return word; // слишком короткое слово

    wstring ending = word.substr(word.size() - 4);
    if (ending != L"онок" && ending != L"ёнок") return word;

    // Определяем последнюю согласную
    wchar_t last_consonant = word[word.size() - 5];
    bool is_shushing = (last_consonant == L'ж' || last_consonant == L'ч' ||
        last_consonant == L'ш' || last_consonant == L'щ');

    // Формируем множественное число
    wstring stem = word.substr(0, word.size() - 4);
    if (is_shushing) {
        return stem + L"ата";
    }
    else {
        return stem + L"ята";
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    wstring input;
    wcout << L"Введите слово (например 'цыпленок(с)'): ";
    getline(wcin, input);

    wstring plural = makePlural(input);
    wcout << L"Множественное число: " << plural << endl;

    return 0;
}