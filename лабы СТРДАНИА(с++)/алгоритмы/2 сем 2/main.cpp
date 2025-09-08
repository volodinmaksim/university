#include <iostream>
#include <string>
using  namespace std;

//номер 2
void rebus_2()
{
	int P[9] = { 1,2,3,4,5,6,7,8,9 }, O[9] = { 1,2,3,4,5,6,7,8,9 }, R[9] = { 1,2,3,4,5,6,7,8,9 }, C[10] = { 0,1,2,3,4,5,6,7,8,9 }, I[10] = { 0,1,2,3,4,5,6,7,8,9 }, Y[10] = { 0,1,2,3,4,5,6,7,8,9 };
	// PROP : O = RCIY
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				for (int h = 0; h < 10; h++)
					for (int g = 0; g < 10; g++)
						for (int b = 0; b < 10; b++)
							if ((P[i] * 1000 + R[j] * 100 + O[k] * 10 + P[i]) / float(O[k]) == float(R[j] * 1000 + C[h] * 100 + I[g] * 10 + Y[b]))
								cout << to_string(P[i]) + to_string(R[j]) + to_string(O[k]) + to_string(P[i]) + " : "
								+ to_string(O[k]) + " = "
								+ to_string(R[j]) + to_string(C[h]) + to_string(I[g]) + to_string(Y[b]) << endl;
}



int main()
{
	rebus_2();
}