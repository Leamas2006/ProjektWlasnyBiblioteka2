#include <iostream>
#include <string>
#include <memory>
#include "Library.h"
#include "Book.h"

int main() {
    Library lib("library.csv");
    try {
        lib.load();
    }
    catch (const std::exception& e) {
        std::cout << "Nie znaleziono pliku lub blad ladowania, generuje przykladowe dane...\n";
        lib.generateSampleData(100);
        try {
            lib.save();
            std::cout << "Zapisano przykladowe dane do pliku.\n";
        }
        catch (const std::exception& ex) {
            std::cerr << "Blad zapisu: " << ex.what() << "\n";
        }
    }

    bool running = true;
    while (running) {
        std::cout << "\nMenu:\n"
            << "1. Wyswietl wszystkie ksiazki\n"
            << "2. Szukaj po tytule\n"
            << "3. Szukaj po autorze\n"
            << "4. Dodaj ksiazke\n"
            << "5. Usun ksiazke\n"
            << "6. Wypozycz ksiazke\n"
            << "7. Zwroc ksiazke\n"
            << "8. Zapisz zmiany\n"
            << "9. Wyjscie\n"
            << "Wybierz opcje: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cout << "Niepoprawny wybor. Sprobuj jeszcze raz.\n";
            continue;
        }
        try {
            switch (choice) {
            case 1:  // Wyswietl wszystkie ksiazki
                lib.displayAll();
                break;
            case 2: {  // Szukaj po tytule
                std::cout << "Podaj fragment tytulu: ";
                std::string kw;
                std::getline(std::cin >> std::ws, kw); //?????? ?? ????????? std::ws, ? ???? ??????????? ?? ????????????? ??????? ??????? ???? ????? ???????
                auto res = lib.searchByTitle(kw);
                for (auto& item : res) std::cout << *item << "\n";
                break;
            }
            case 3: {  // Szukaj po autorze
                std::cout << "Podaj fragment nazwiska autora: ";
                std::string kw;
                std::getline(std::cin >> std::ws, kw);
                auto res = lib.searchByAuthor(kw);
                for (auto& item : res) std::cout << *item << "\n";
                break;
            }
            case 4: {  // Dodaj ksiazke
                int id, year, copies;
                std::string author, title, isbn, publisher, location;
                std::cout << "Podaj ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Podaj autora: ";
                std::getline(std::cin, author);
                std::cout << "Podaj tytul: ";
                std::getline(std::cin, title);
                std::cout << "Podaj rok wydania: ";
                std::cin >> year;
                std::cin.ignore();
                std::cout << "Podaj ISBN: ";
                std::getline(std::cin, isbn);
                std::cout << "Podaj wydawnictwo: ";
                std::getline(std::cin, publisher);
                std::cout << "Podaj liczbe egzemplarzy: ";
                std::cin >> copies;
                std::cin.ignore();
                std::cout << "Podaj miejsce przechowywania: ";
                std::getline(std::cin, location);
                lib.addItem(std::make_shared<Book>(id, author, title, year, isbn, publisher, copies, location));
                std::cout << "Dodano ksiazke.\n";
                break;
            }
            case 5: {  // Usun ksiazke
                int id;
                std::cout << "Podaj ID do usuniecia: "; std::cin >> id;
                lib.removeById(id);
                std::cout << "Usunieto ksiazke.\n";
                break;
            }
            case 6: {  // Wypozycz ksiazke
                int id;
                std::cout << "Podaj ID do wypozyczenia: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Podaj imie i nazwisko wypozyczajacego: ";
                std::string borrower;
                std::getline(std::cin, borrower);
                lib.checkOut(id, borrower);
                std::cout << "Wypozyczono ksiazke.\n";
                break;
            }
            case 7: {  // Zwroc ksiazke
                int id;
                std::cout << "Podaj ID do zwrotu: "; std::cin >> id;
                lib.returnItem(id);
                std::cout << "Zwrocono ksiazke.\n";
                break;
            }
            case 8:  // Zapisz zmiany
                lib.save();
                std::cout << "Zapisano zmiany.\n";
                break;
            case 9:  // Wyjscie
                running = false;
                break;
            default: // Nieznana opcja
                std::cout << "Nieznana opcja.\n";
                break;
            }
        }
        catch (const std::exception& e) {
            std::cout << "Blad: " << e.what() << "\n";
        }
    }

    return 0;
}
