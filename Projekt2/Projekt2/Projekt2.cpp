// Projekt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

/*
	Implementacja gdy tablice do posortowania sa wektorami
	table - tabela nieposortowana (nalezalo posortowac kopie tej tablicy)
	result - wynik dzialania zaimplementowanego algorytmu na kopii zmienne table
*/
template<typename T>
bool checkIfCorrect(std::vector<T> table, const std::vector<T>& result)
{
	// mozna za pomoca metody std::sort zaimpelmentowac czesciowe sortowanie tablicy wejsciowej algorytmu,
	// nalezy odpowiednio operowac na iteratorach (chodzi o 2. argument)
	std::sort(table.begin(), table.end());
	return (table == result);
}

/*
Implementacja gdy tablice do posortowania sa zwyklymi tablicami
table - tabela nieposortowana (nalezalo posortowac kopie tej tablicy)
result - wynik dzialania zaimplementowanego algorytmu na kopii zmienne table
*/
template<typename T, size_t N>
bool checkIfCorrect(const T (&table)[N], const  T (&result)[N])
{
	T sorted[N];
	std::copy(table, table + N, sorted);
	std::sort(std::begin(sorted), std::end(sorted));

	return std::equal(std::begin(sorted), std::end(sorted),
		std::begin(result), std::end(result));
}

int main()
{
	//srand(time(NULL));

	std::vector<int> nVector{10000, 50000, 100000,500000, 1000000};
	const int nbOfExperiments = 100;

	/*Badanie dla ka¿dego rozmiaru tablicy n*/
	for (const auto& n : nVector)
	{
		/*Wykonanie eksperymentu nbOfExperiments razy dla tablic o rozmiarze n*/
		for (int i = 0; i < nbOfExperiments; ++i)
		{
			/*
			Przygotowanie tablic o rozmiarze n:
			•wszystkie elementy tablicy losowe,
			• 25%, 50%, 75%, 95%, 99%, 99,7% pocz¹tkowych elementów tablicy jest ju¿ posortowanych,
			• wszystkie elementy tablicy ju¿ posortowane ale w odwrotnej kolejnoœci.
			Mozna uzyc metody std::generate do zapelnienia swojej tablicy wejsciowej.
			*/


			/* Mierzenie czasu trwania jednego eksperymentu
			Poni¿szy fragment wykonywany jest wielokrotnie 
			osobno dla ka¿dej kombinacji algorytmu i tablicy wejœciowej*/
			auto start = std::chrono::system_clock::now();
			//pojedyncze wykonanie jednego algorytmu sortowania dla jednej tablicy
			//swoje implementacje sortowania na kopii tablic wejœciowych
			auto end = std::chrono::system_clock::now();

			std::chrono::duration<double> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
			double durationTime = diff.count(); // zmierzony czas zapisaæ do pliku lub zagregowaæ, zapisaæ liczbê badanych elementów
		
			/*Sprawdzenie poprawnoœci dzia³ania algorytmu, juz po pomiarze czasu
			checkIfCorrect(tablica_nieposortowana, tablica_posortowana_algorytmem);
			*/
		}
	}
	return 0;
}

