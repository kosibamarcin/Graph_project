## Jakie problemy rozwiązuje ?
Algorytm Bellmana-Forda służy do znajdywania najkrótszej ścieżki od wybranego wierzchołka 
startowego do wybranego wierzchołka końcowego. Najkrótszej ścieżki, czyli takiej, dla której
suma wag pokonanych krawędzi będzie najmniejsza. Algorytm jest wolniejszy od algorytmu Dijkstry,
ale w odróznieniu od niego dopuszcza krawędzie o ujemnych wagach. Ograniczeniem jest jednak konieczność
braku występowania ujemnych cykli, gdyż wtedy cykl taki może służyć do zbijania poniesionych kosztów.

## Przykłady wykorzystania:
1. Distance-Vector routing protocol - ten protokół decyduje w jaki sposób pokierować dane w sieci.
Wagami w tym przypadku jest liczba routerów na drodze do danej destynacji.
2. Przede wszystkim - Routing Information protocol - jeden z najstarszych protokołów internetowych,
który zapobiega zapętlaniu.
3. Destination-Sequenced Distance-Vector Routing - kolejny protokół, który korzysta z algorytmu Bellmana-Forda.
4. Innym oczywistym zastosowaniem może być najzwyczajniesze użycie algorytmu do znalezienia najkrótszej 
ścieżki w grafie z ujemnymi wagami.

## Obecne metody do rozwiązywania tych problemów:
1. W przypadku Routing Information protocol używa sie teraz techniki split-horizon route advertisement,
która zmniejsza szanse na pojawienie się cykli i wykrywa problem 'count to infinity'.
2. W ostatnich latach podobne protokoły uległy ulepszeniu wskutek zastosowania link state routing protocols,
które korzystają z map dystrybucji (ang. distributing maps), a następnie korzystają z jakiejś wersji 
algorytmu Dijkstry.
