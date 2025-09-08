#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pair1 
{
	char symbol;
	bool flag;
	Pair1()
	{
		symbol = ' ';
		flag = true;
	}
	Pair1(char symbol)
	{
		this->symbol = symbol;
		flag = true;
	}
	
};

void printMatrix(vector<vector<Pair1>> M, int n)
{
	for (int i{}; i < n; i++)
	{
		for (int j{}; j < n; ++j)
		{
			cout << M[i][j].symbol << M[i][j].flag << ' ';
		}
		cout << '\n';
	}
}

string find_word(vector<vector<Pair1>> M, int n, int i, int j, int amount_searched, string word, bool &flag_dio)
{
	M[i][j].flag = false;
	if (amount_searched == word.length())
		return "Yes";

	if (i > 0 && M[i - 1][j].symbol == word[amount_searched] && M[i - 1][j].flag == true)
		return find_word(M, n, i - 1, j, amount_searched + 1, word, flag_dio);
	else if (i < n - 1 && M[i + 1][j].symbol == word[amount_searched] && M[i + 1][j].flag == true)
		return find_word(M, n, i + 1, j, amount_searched + 1, word, flag_dio);
	else if (j > 0 && M[i][j - 1].symbol == word[amount_searched] && M[i][j - 1].flag == true)
		return find_word(M, n, i, j - 1, amount_searched + 1, word, flag_dio);
	else if (j < n - 1 && M[i][j + 1].symbol == word[amount_searched] && M[i][j + 1].flag == true)
		return find_word(M, n, i, j + 1, amount_searched + 1, word, flag_dio);

	else if (i > 0 && j > 0 && flag_dio == true && M[i - 1][j - 1].symbol == word[amount_searched] && M[i - 1][j - 1].flag == true)
	{
		flag_dio = false;
		return find_word(M, n, i - 1, j - 1, amount_searched + 1, word, flag_dio);
	}
	else if (i > 0 && j < n - 1 && flag_dio == true && M[i - 1][j + 1].symbol == word[amount_searched] && M[i - 1][j + 1].flag == true)
	{
		flag_dio = false;
		return find_word(M, n, i - 1, j + 1, amount_searched + 1, word, flag_dio);
	}
	else if (i < n - 1 && j < n - 1 && flag_dio == true && M[i + 1][j + 1].symbol == word[amount_searched] && M[i + 1][j + 1].flag == true)
	{
		flag_dio = false;
		return find_word(M, n, i + 1, j + 1, amount_searched + 1, word, flag_dio);
	}
	else if (i < n - 1 && j > 0 && flag_dio == true && M[i + 1][j - 1].symbol == word[amount_searched] && M[i + 1][j - 1].flag == true)
	{
		flag_dio = false;
		return find_word(M, n, i + 1, j - 1, amount_searched + 1, word, flag_dio);
	}
	else
		return "No";
}

int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Введите размер матрицы \n";
	cin >> n;
	cout << "Введите матрицу \n";
	vector<vector<Pair1>> M(n);
	Pair1 per;
	for (int i{}; i < n; i++)
	{
		for (int j{}; j < n; ++j)
		{
			cin >> per.symbol;
			M[i].push_back(per);
		}
	}
	string word;
	cout << "Введите искомое слово \n";
	cin >> word;

	//---------------------------------------------------
	int amount_searched{};
	string res("No");
	bool flag_dio(true);
	for (int i{}; i < n; ++i)
	{
		for (int j{}; j < n; ++j)
		{
			if (M[i][j].symbol == word[0])
			{
				M[i][j].flag = false;
				res = find_word(M, n, i, j, amount_searched + 1, word, flag_dio);
			}
			if (res == "Yes")
			{
				break;
			}
		}
		if (res == "Yes")
		{
			break;
		}
	}
	cout << res << '\n';

}
