#pragma once
#include <raylib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>		
#include <vector>  
#include <cstdlib>
#include <math.h>
#include "Queue.h"

using namespace std;

class AVLTree
{
	struct Node
	{
		int data;
		unsigned char height;
		Node* left;
		Node* right;
		Node(int _data): data(_data), left(nullptr), right(nullptr), height(1) {}
	};

	Node* root;

	unsigned char height(Node* p);
	void fixHight(Node* p);
	int balanceFactor(Node* p);
	void RR_rotate(Node*& p);
	void LL_rotate(Node*& p);
	void balance(Node*& p);
	void insert(Node*& root, int elem);
	int findMin(Node* root);


	void remove(Node*& root, int elem);

	Node* minValueNode(Node* node);


	void clear(Node*& p);

	void drawTree(int x, int y, int radius, int size, Font font, Node* root, int level, int* frequencies);
	

	void postorder(Node* root);

	void DrawStar(Vector2 position, int radius, Color color1, Color color2)
	{
		DrawCircleGradient(position.x, position.y, radius, color1, color2);
	}
	void DrawComet(Vector2 position, int length, int width, Color color1, Color color2)
	{
		DrawRectangleGradientV(position.x, position.y - length / 2, width, length, color1, color2);
	}
	void DrawMoon();
	void countDigitFrequencies(Node* root, int*& frequencies);
	
	void deleteNumber(Node*& root, int* frequencies, int*& musInsert, int*& musDelete, int & indexI, int& indexD);

public:

	AVLTree():root(nullptr) {}
	~AVLTree()	{	clear();	}

	unsigned char getHight() { return height(root); }

	void insert(int elem) { insert(root, elem); }

	void remove(int elem) { remove(root, elem); }
	void clear() { clear(root); }

	int findMin() { return findMin(root); }
	
	void drawTree();

	void deleteNumber() {
		int *frequencies = new int[10];
		int* musInsert = new int[100];
		int* musDelete = new int[100];
		int indexI = 0, indexD = 0;
		for (int i = 0; i < 10; i++)
			frequencies[i] = 0;
		countDigitFrequencies(root, frequencies); 
		deleteNumber(root, frequencies, musInsert, musDelete, indexI, indexD);
		for (int i = 0; i < indexD; i++)
		{
			remove(musDelete[i]);
		}
		for (int i = 0; i < indexI; i++)
		{
			insert(musInsert[i]);
		}
		
	};

	void postorder() { postorder(root); };

};