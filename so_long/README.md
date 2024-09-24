
# 🕹️ **Gra "so_long"** 🕹️

## 🎮 **Opis Gry**

"so_long" to prosta, ale wciągająca gra 2D typu "top-down", w której gracz wciela się w bohatera eksplorującego tajemniczy labirynt. Celem gry jest zebranie wszystkich przedmiotów (kolekcji) i dotarcie do wyjścia, unikając przeszkód w postaci ścian.
---

## 🚀 **Rozgrywka**

- **Zadanie gracza:** Zbierz wszystkie "C" (kolekcje) rozrzucone po planszy i dotrzyj do wyjścia oznaczonego literą "E".
- **Przeszkody:** Nie możesz przejść przez ściany oznaczone jako "1". Musisz unikać takich przeszkód podczas poruszania się.
- **Poruszanie się:** Gracz porusza się po planszy używając klawiszy:
  - `W` - ruch w górę
  - `S` - ruch w dół
  - `A` - ruch w lewo
  - `D` - ruch w prawo
- **Zakończenie gry:** Gra kończy się, gdy gracz zbierze wszystkie kolekcje i dotrze do wyjścia.

---

## 📦 **Instalacja i Uruchomienie Gry**

1. **Klonowanie repozytorium:**
   Aby pobrać kod źródłowy, użyj polecenia:
   ```bash
   git clone https://github.com/twoj-uzytkownik/twoje-repozytorium.git
   ```

2. **Kompilacja:**
   Po pobraniu repozytorium, skompiluj grę za pomocą Makefile:
   ```bash
   make
   ```

3. **Uruchomienie:**
   Po kompilacji uruchom grę za pomocą poniższego polecenia, podając plik mapy:
   ```bash
   ./so_long maps/mapa.ber
   ```

4. **Wymagania systemowe:**
   - **System:** Gra została przetestowana na systemie Linux i macOS.
   - **Biblioteki:** Gra korzysta z biblioteki MiniLibX, która zapewnia podstawowe funkcje do obsługi grafiki oraz zdarzeń na poziomie systemowym.
   - **Obsługiwane formaty map:** Mapa powinna być zapisana w formacie `.ber` i odpowiednio sformatowana. Każdy znak na mapie reprezentuje różne elementy:
     - **'1'** - ściana, przez którą nie można przejść.
     - **'0'** - puste pole, po którym można się poruszać.
     - **'P'** - początkowa pozycja gracza.
     - **'C'** - kolekcja do zebrania.
     - **'E'** - wyjście, które stanie się aktywne, gdy wszystkie kolekcje zostaną zebrane.

---

## 🗺️ **Przykładowa Mapa**

```
111111
1P0C01
100001
1C0E11
111111
```

- W powyższym przykładzie gracz zaczyna w pozycji oznaczonej literą **P**, zbiera wszystkie **C**, i kończy grę, docierając do wyjścia **E**.

---

## 🛠️ **Zależności**

Gra wymaga zainstalowania następujących narzędzi:

- **MiniLibX** - biblioteka graficzna używana do obsługi grafiki 2D oraz wyświetlania okien gry.
- **make** - narzędzie do kompilacji.
- **gcc** - kompilator C.

---

## 🧑‍💻 **Jak stworzyć własną mapę?**

1. Otwórz dowolny edytor tekstu i stwórz nowy plik z rozszerzeniem `.ber`.
2. Każdy wiersz powinien mieć tę samą długość, a mapa musi być otoczona ścianami (`1`).
3. Dodaj elementy na mapie zgodnie z zasadami:
   - Przynajmniej jedna pozycja gracza (`P`), jedno wyjście (`E`) i jedna kolekcja (`C`).
   
4. Przykład zapisania mapy do pliku `mapa.ber`:
   ```txt
   1111
   1P01
   1C01
   1E11
   1111
   ```

---

## 🧩 **Dodatkowe funkcje**

- **Licznik ruchów:** Podczas rozgrywki liczba ruchów gracza jest wyświetlana w terminalu.
- **Obsługa klawisza ESC:** Wciśnięcie klawisza `ESC` powoduje natychmiastowe zamknięcie gry.
- **Końcowy stan gry:** Gra automatycznie zamyka się po zebraniu wszystkich kolekcji i dotarciu do wyjścia.

---

## 💡 **Wskazówki dla programistów**

- Gra została napisana w języku C i wymaga znajomości podstawowych mechanizmów programowania niskopoziomowego, takich jak zarządzanie pamięcią i wskaźnikami.
- Projekt zawiera dobrze zorganizowane moduły, takie jak:
  - **graphics.h** - obsługuje elementy związane z grafiką.
  - **map.h** - zarządza funkcjami związanymi z wczytywaniem i analizą mapy.
  - **utils.h** - pomocnicze funkcje ułatwiające pracę z różnymi strukturami danych.
- **Norminette**: Kod został napisany zgodnie z surowymi standardami norminette.

---

## 📜 **Licencja**

Projekt ten jest dostępny na licencji MIT. Możesz go używać, modyfikować i rozpowszechniać pod warunkiem zachowania praw autorskich. 

---

Mam nadzieję, że gra Ci się spodoba! 😊
