// This code has not passed OJ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SnakeGame{
	int width, height, score;
	vector<pair<int, int>> food, snake;
public:
	/** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
    */
	SnakeGame(int width, int height, vector<pair<int, int>> food){
		this->width = width;
		this->height = height;
		this->food = food;
		score = 0;
		snake.push_back(make_pair(0,0));
	}

	/** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body.
		Bites itself if: After removing head of snake if count of head of snake
		again becomes 1
    */
    int move(string direction){
    	pair<int,int> head, tail, fpos;
    	head = snake.front();
    	tail = snake.back();
    	// Pop tail everytime but if after incrementing head we reach a
    	// food position then again push tail and of course the new head
    	snake.pop_back();

    	if (direction == "U") --head.first;
    	else if (direction == "D") ++head.first;
    	else if (direction == "L") --head.second;
    	else if (direction == "R") ++head.second;

    	// count(snake.begin(), snake.end(), head) means that pos already exist
    	// implies the new pos might bit the snake itself
    	if (head.first < 0 || head.first >= height || head.second < 0 || head.second >= width || count(snake.begin(), snake.end(), head))
        {
            //if (count(snake.begin(), snake.end(), head))
            //    cout<<"Snake bite itself. Game Over!!!"<<endl;
            return -1;
        }
    	// u always insert new pos unless it crosses boundary
    	// or bites itself
    	snake.insert(snake.begin(), head);

    	if (!food.empty() && head == food.front())
    	{
    		score ++;
    		snake.push_back(tail);
    		// not food.erase(food.front()), need iterator
    		food.erase(food.begin());
    	}

    	return score;
    }
};

int main()
{
    int w = 3;
    int h = 2;
    vector<pair<int, int>> food;
    food.push_back(make_pair(1,2));
    food.push_back(make_pair(0,2));
    food.push_back(make_pair(0,1));
    food.push_back(make_pair(1,1));


    // 2 ways to create objects
    // Just declaring a object of type class
    SnakeGame sg(w, h, food);
    // Secondly by dynamically creating
    //SnakeGame* sg = SnakeGame(w, h, food);
    cout<<"R "<<sg.move("R")<<endl;
    cout<<"D "<<sg.move("D")<<endl;
    cout<<"R "<<sg.move("R")<<endl;
    cout<<"U "<<sg.move("U")<<endl;
    cout<<"L "<<sg.move("L")<<endl;
    //cout<<"U "<<sg.move("U")<<endl;
    cout<<"U "<<sg.move("D")<<endl;
    cout<<"U "<<sg.move("R")<<endl;
    return 0;
}
