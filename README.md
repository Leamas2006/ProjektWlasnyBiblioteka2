# 📚 Projekt Własny – System Biblioteczny (C++)

## 📖 Opis projektu
System zarządzania **biblioteką multimedialną** napisany w języku **C++**.  
Aplikacja umożliwia przechowywanie i obsługę różnych typów mediów:

- 📕 Książki
- 🎬 Filmy
- 📰 Czasopisma

Dane przechowywane są w pliku **CSV** (`library.csv`), co pozwala na zapis i odczyt między uruchomieniami programu.

---

## ✨ Funkcjonalności
- ➕ Dodawanie nowych pozycji do biblioteki  
- 📋 Wyświetlanie listy wszystkich elementów  
- 🔍 Wyszukiwanie mediów według wybranych kryteriów  
- ❌ Usuwanie elementów z biblioteki  
- 🏷 Obsługa wielu typów mediów dzięki dziedziczeniu z klasy `MediaItem`  
- 👤 Zarządzanie użytkownikami biblioteki  

---

## 📂 Struktura projektu
```bash
├── Book.cpp / Book.h           # Klasa reprezentująca książkę
├── Film.cpp / Film.h           # Klasa reprezentująca film
├── Magazine.cpp / Magazine.h   # Klasa reprezentująca czasopismo
├── MediaItem.cpp / MediaItem.h # Klasa bazowa dla wszystkich mediów
├── User.cpp / User.h           # Klasa użytkownika
├── Library.cpp / Library.h     # Klasa zarządzająca kolekcją mediów
├── main.cpp                    # Główna funkcja programu
├── library.csv                 # Plik z danymi biblioteki
├── Project2.sln / .vcxproj     # Pliki projektu Visual Studio
```

---

## ⚙️ Wymagania
- Kompilator **C++11** lub nowszy  
- **Visual Studio 2019/2022** lub inny kompatybilny edytor  
- System: **Windows / Linux / macOS**  

---

## 🚀 Kompilacja i uruchomienie

### 🔹 Visual Studio
1. Otwórz plik `Project2.sln` w Visual Studio  
2. Wybierz konfigurację **Debug** lub **Release**  
3. Wciśnij **F5**, aby uruchomić projekt  

### 🔹 Terminal (g++)
```bash
g++ -std=c++11 main.cpp Book.cpp Film.cpp Magazine.cpp MediaItem.cpp User.cpp Library.cpp -o biblioteka
./biblioteka
```

---

## 💻 Przykładowe użycie
```plaintext
=== Biblioteka Multimedialna ===
1. Dodaj książkę
2. Dodaj film
3. Dodaj czasopismo
4. Wyświetl wszystkie pozycje
5. Wyszukaj po tytule
6. Usuń pozycję
0. Wyjście

Wybierz opcję: 1
Podaj tytuł: Władca Pierścieni
Podaj autora: J.R.R. Tolkien
Podaj rok wydania: 1954
Pozycja została dodana!
```

---

## 👤 Autor
Dmytro Dontsov

Projekt przygotowany w ramach zajęć uniwersyteckich.
