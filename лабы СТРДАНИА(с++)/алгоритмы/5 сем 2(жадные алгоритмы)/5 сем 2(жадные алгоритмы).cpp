#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Pair 
{
	int first;
	int second;
	int max_elem;

	void set_max()
	{
		if (first > second)
			max_elem = first;
		else 
			max_elem = second;
	}
	bool operator>(const Pair& obj)
	{
		if (this->max_elem > obj.max_elem)
			return true;
		return false;
	}
	bool operator<=(const Pair& obj)
	{
		return !this->operator>(obj);
	}
	bool operator<(const Pair& obj)
	{
		if (this->max_elem < obj.max_elem)
			return true;
		return false;
	}
	bool operator>=(const Pair& obj)
	{
		return !this->operator<(obj);
	}
	bool operator==(const Pair& obj)
	{
		if (this->max_elem == obj.max_elem)
			return true;
		return false;
	}
	bool operator!=(const Pair& obj)
	{
		return !this->operator==(obj);
	}

} temp;

void print_mass(vector<Pair> mass, int n)
{
	for (int i{}; i < n; ++i)
		cout << "(" << mass[i].first << ", " << mass[i].second << ")  ";
	cout << "\n";
}

void reverse(vector<Pair>& mass, int n)
{
	int num{};
	for (int i{}; i < n; ++i)
	{
		num = mass[i].first;
		mass[i].first = mass[i].second;
		mass[i].second = num;
	}
}

int main()
{
	int n, g, h;
	cin >> n >> g >> h;
	vector<Pair> mass(n);
	for (int i{}; i < n; ++i)
	{
		cin >> temp.first >> temp.second;
		temp.set_max();
		mass[i] = temp;
	}
	sort(mass.rbegin(), mass.rend());

	
	int power_sum = 0;
	int amount_now = n;
	while (!((g == 0 || h == 0) && g + h == amount_now)) 
	{
		if (amount_now == 0)
			break;
		if (mass[n - amount_now].first > mass[n - amount_now].second)
		{
			power_sum += mass[n - amount_now].first;
			--g; --amount_now;
		}
		else if (mass[n - amount_now].first == mass[n - amount_now].second)
		{
			if (g > h)
			{
				power_sum += mass[n - amount_now].first;
				--g; --amount_now;
			}
			else
			{
				power_sum += mass[n - amount_now].second;
				--h; --amount_now;
			}
		}
		else
		{
			power_sum += mass[n - amount_now].second;
			--h; --amount_now;
		}
	}
	
	if (amount_now == 0)
	{
		if (h <= 0 && g <= 0)
		{
			cout << power_sum << "\n" <<g<< "\n" <<h<< endl;
			return 0;
		}
		else
		{
			cout << -1 << endl;
			return 0;
		}
	}

	if (h > 0)
		for (int i = amount_now; amount_now != 0; --amount_now) 
		{
			power_sum += mass[n - amount_now].second;
			h--;
		}
	if (g > 0)
		for (int i = amount_now; amount_now != 0; --amount_now)
		{
			power_sum += mass[n - amount_now].first;
			g--;
		}

	cout << power_sum << "\n" << g << "\n" << h << endl;
}