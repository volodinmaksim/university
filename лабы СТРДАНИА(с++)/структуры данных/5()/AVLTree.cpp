#include "AVLTree.h"

unsigned char AVLTree::height(Node* p)
{
	return p ? p->height : 0;
}

void AVLTree::fixHight(Node* p)
{
	if (!p)return;
	unsigned char hL = height(p->left);
	unsigned char hR = height(p->right);
	p->height = (hL > hR ? hL : hR) + 1;
}

int AVLTree::balanceFactor(Node* p)
{
	return  height(p->right) - height(p->left);
}

void AVLTree::RR_rotate(Node*& p)
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixHight(p);
	fixHight(q);
	p = q;
}

void AVLTree::LL_rotate(Node*& p)
{
	Node* q = p->right;
	p->right = q->left;
	q->left = p;
	fixHight(p);
	fixHight(q);
	p = q;
}

void AVLTree::balance(Node*& p)
{
	fixHight(p);

	if (balanceFactor(p) == 2)
	{
		if (balanceFactor(p->right) < 0)
			RR_rotate(p->right);
		LL_rotate(p);
	}

	if (balanceFactor(p) == -2)
	{
		if (balanceFactor(p->left) > 0)
			LL_rotate(p->left);
		RR_rotate(p);
	}
}

void AVLTree::insert(Node*& root, int elem)
{
	if (!root) {
		root = new Node(elem);
	}
	else if (elem < root->data)
		insert(root->left, elem);
	else if (elem > root->data)
		insert(root->right, elem);
	balance(root);
}

int AVLTree::findMin(Node* root)
{
	return root->left ? findMin(root->left) : root->data;
}

void AVLTree::remove(Node*& root, int elem)
{
	if (!root) return;

	if (elem < root->data)
		remove(root->left, elem);
	else if (elem > root->data)
		remove(root->right, elem);
	else
	{
		if (!root->left || !root->right)
		{
			Node* temp = root->left ? root->left : root->right;

			if (!temp)
			{
				temp = root;
				root = nullptr;
			}
			else
			{
				*root = *temp;
			}
			delete temp;
		}
		else
		{
			Node* temp = minValueNode(root->right);
			root->data = temp->data;
			remove(root->right, temp->data);
		}
	}

	if (root == nullptr) return;

	balance(root);
}

AVLTree::Node* AVLTree::minValueNode(Node* node)
{
	Node* current = node;

	while (current->left != nullptr)
		current = current->left;

	return current;
}

void AVLTree::clear(Node*& p)
{
	if (p)
	{
		clear(p->left);
		clear(p->right);
		delete p;
		p = nullptr;
	}
}






void AVLTree::DrawMoon()
{
	{
		DrawCircleGradient(1280, 130, 140, YELLOW, WHITE1);
		DrawCircle(1280, 130, 120, Zvezda);


		DrawEllipse(1200, 140, 34, 34, WHITE);
		DrawEllipse(1280, 190, 24, 24, WHITE);
		DrawEllipse(1350, 120, 39, 39, WHITE);
		DrawEllipse(1335, 55, 24, 23, WHITE);
		DrawEllipse(1240, 80, 29, 29, WHITE);
		DrawEllipse(1240, 120, 7, 7, WHITE);
		DrawEllipse(1340, 180, 9, 9, WHITE);

		DrawEllipse(1200, 140, 30, 30, KRATER);
		DrawEllipse(1280, 190, 20, 20, KRATER);
		DrawEllipse(1350, 120, 35, 35, KRATER);
		DrawEllipse(1335, 55, 20, 19, KRATER);
		DrawEllipse(1240, 80, 25, 25, KRATER);
		DrawEllipse(1240, 120, 5, 5, KRATER);
		DrawEllipse(1340, 180, 7, 7, KRATER);
	}
}


void AVLTree::countDigitFrequencies(Node* root, int*& frequencies)
{
	if (!root) return;

	int num = abs(root->data); 

	while (num > 0)
	{
		int digit = num % 10;
		frequencies[digit]++;
		num /= 10;
	}

	countDigitFrequencies(root->left, frequencies);
	countDigitFrequencies(root->right, frequencies);
}


void AVLTree::deleteNumber(Node*& root, int* frequencies, int*& musInsert, int*& musDelete, int& indexI, int& indexD)
{
	if (root == nullptr)
		return;

	deleteNumber(root->left, frequencies, musInsert, musDelete, indexI, indexD);
	deleteNumber(root->right, frequencies, musInsert, musDelete, indexI, indexD);
	
	string elem = to_string(root->data);
	string newElem = "";
	bool flag = false;
	for (char ch : elem)
	{
		if (frequencies[ch - '0'] > 1)
			flag = true;
		else
			newElem += ch;
	}
	if (flag)
	{
		musDelete[indexD] = root->data;
		indexD++;
	}
	if (!newElem.empty())
	{
		if (stoi(newElem) == root->data)
			return;
		int num = stoi(newElem);
		musInsert[indexI] = num;
		indexI++;
	}
}



struct Star
{
	Vector2 position;
	Vector2 velocity;
};

struct Comet
{
	Vector2 position;
	Vector2 velocity;
	int length;
	int width;
};





void AVLTree::drawTree()
{
	const int screenWidth = 1480; 
	const int screenHeight = 1000;

	InitWindow(screenWidth, screenHeight, "AVL Tree");
	SetTargetFPS(60);

	DrawRectangleGradientV(0, 0, screenWidth, screenHeight, BLACK, MIDNIGHTBLUE);


	Font font = LoadFont("Enema.ttf");
	SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);


	// Подсчет частот цифр в дереве
	int* frequencies= new int[10];
	for (int i = 0; i < 10; i++)
		frequencies[i] = 0;
	countDigitFrequencies(root, frequencies);

	// Мерцание звезд
	static float alpha = 0.0f;
	alpha += 0.01f;
	if (alpha > 1.0f) alpha = 0.0f;
	float brightness = 1.0f + 0.2f * sinf(alpha * 2.0f * PI);


	std::srand(std::time(0));

	// Создаем массивы звезд и комет
	std::vector<Star> stars;
	std::vector<Comet> comets;

	// Инициализация звезд
	for (int i = 0; i < 100; ++i) // Количество звезд
	{
		Star star;
		star.position = { (float)(std::rand() % screenWidth), (float)(std::rand() % screenHeight) };
		star.velocity = { (float)(std::rand() % 50 - 25) / 100.0f, (float)(std::rand() % 50 - 25) / 100.0f }; // Медленная скорость
		stars.push_back(star);
	}

	// Инициализация комет
	for (int i = 0; i < 10; ++i) // Количество комет
	{
		Comet comet;
		comet.position = { (float)(std::rand() % screenWidth), (float)(std::rand() % screenHeight) };
		comet.velocity = { (float)(std::rand() % 50 - 25) / 100.0f, (float)(std::rand() % 50 - 25) / 100.0f }; // Медленная скорость
		comet.length = 10 + std::rand() % 20; // Длина кометы
		comet.width = 2 + std::rand() % 3; // Ширина кометы
		comets.push_back(comet);
	}

	

	while (!WindowShouldClose()) {
		
		for (Star& star : stars)
		{
			star.position.x += star.velocity.x;
			star.position.y += star.velocity.y;

			if (star.position.x < 0) star.position.x = screenWidth;
			if (star.position.x > screenWidth) star.position.x = 0;
			if (star.position.y < 0) star.position.y = screenHeight;
			if (star.position.y > screenHeight) star.position.y = 0;
		}

		for (Comet& comet : comets)
		{
			comet.position.x += comet.velocity.x;
			comet.position.y += comet.velocity.y;

			if (comet.position.x < 0) comet.position.x = screenWidth;
			if (comet.position.x > screenWidth) comet.position.x = 0;
			if (comet.position.y < 0) comet.position.y = screenHeight;
			if (comet.position.y > screenHeight) comet.position.y = 0;
		}
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangleGradientV(0, 0, screenWidth, screenHeight, BLACK, ColorAlpha(MIDNIGHTBLUE, (unsigned char)(brightness * 255)));
		
		for (const Star& star : stars)
		{
			DrawStar(star.position, 2 + std::rand() % 3, WHITE, LIGHTGRAY);
		}

		for (const Comet& comet : comets)
		{
			DrawComet(comet.position, comet.length, comet.width, WHITE, LIGHTGRAY);
		}


		DrawMoon();
		drawTree(screenWidth/2, 180, 33, 28, font, root, 0, frequencies);
		EndDrawing();
	}
	CloseWindow();
}








void AVLTree::drawTree(int x, int y, int radius, int size, Font font, Node* root, int level, int* frequencies)
{
	if (!root) return;

	Vector2 v1 = { (float)x + 2, (float)y + 2 };
	DrawPoly(v1, 3, radius, 180 / 3 * 1, DARKGRAY);
	DrawPoly(v1, 3, radius, 180 / 3 * 2, DARKGRAY);

	v1 = { (float)x, (float)y };
	DrawPoly(v1, 3, radius, 180 / 3 * 1, Zvezda);
	DrawPoly(v1, 3, radius, 180 / 3 * 2, Zvezda);

	float k = (root->data < -9 || root->data > 9) ? 1.75 : 3;
	int textSize = size * 0.6; 
	Vector2 textMeasure = MeasureTextEx(font, TextFormat("%i", root->data), textSize, 0);
	Vector2 textPosition = { (float)x - textMeasure.x / 2, (float)(y - radius / 2.0) };
	

	
	int num = abs(root->data);
	string numberStr = to_string(num);
	float digitWidth = textMeasure.x / numberStr.length();
	float startX = textPosition.x;

	for (char digitChar : numberStr)
	{
		int digit = digitChar - '0';
		Color textColor = (frequencies[digit] > 1) ? RED : BLACK;
		DrawTextEx(font, TextFormat("%c", digitChar), { startX, textPosition.y }, textSize, 0, textColor);
		startX += digitWidth;
	}


	int levelDistance = 100;
	int horizontalDistance = 10 * pow(2, level); 
	
	if (root->left)
	{
		int newX = x - 7 * pow(2, root->height);
		DrawLineEx({ (float)x, (float)(y + radius) }, { (float)newX, (float)(y + levelDistance) }, 2.0, LIGHTGRAY);
		drawTree(newX, y + levelDistance, radius - 2, size, font, root->left, level + 1, frequencies);
	}

	if (root->right)
	{
		int newX = x + 7 * pow(2, root->height);
		DrawLineEx({ (float)x, (float)(y + radius) }, { (float)newX, (float)(y + levelDistance) }, 2.0, LIGHTGRAY);
		drawTree(newX, y + levelDistance, radius - 2, size, font, root->right, level + 1, frequencies);
	}
}

void AVLTree::postorder(Node* root)
{
	if (!root) return;

	postorder(root->left);
	postorder(root->right);
	std::cout << root->data << " ";

}
