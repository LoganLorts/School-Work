//Programer:	Logan Lorts
//Date:		5/5/23
//Professor:	Jack Manhardt


#include <iostream>
using namespace std;

int traverse_maze(char **maze, int y, int x)
{
    int direction = 0, success;
    int y2;
    int x2;
    do
    {
    switch(direction){
    case 0:
        y2 = y-1;
        x2 = x;
        break;
    case 1:
        y2 = y;
        x2 = x+1;
        break;
    case 2:
        y2 = y+1;
        x2 = x;
        break;
    case 3:
        y2 = y;
        x2 = x-1;
    }

    if(maze[y2][x2] == ' ')
    {
        maze[y2][x2] = '.';
        success = traverse_maze(maze, y2,x2);
        if(success)
        {
            return 1;
        }
    }
    else if (maze[y2][x2] == 'E')
    {
        return 1;
    }

    ++direction;
    }while(direction < 4);
    maze[y][x] = ' ';
    return 0;
}

int main()
{
    int cs = 0,rs = 0, mazes_solved = 0;
    char** maze;
    int x = 0, y = 0;

    do
    {
        //take input for maze
        cin >> cs >> rs;
        if((cs < 0) || rs < 0)
        {
            cout << "invalid maze size" << endl;
            break;
        }
        if((cs == 0) || (rs == 0))
        {
            break;
        }
        cin.ignore();

        //create maze
        maze = new char*[rs];
        for(int k=0; k < rs;k++)
        {
            maze[k] = new char[cs];
        }

        //fill maze
        char endline_char;
        for(int k =0; k<rs; k++)
        {
            for(int j=0;j<cs;j++)
            {
                cin.get(maze[k][j]);
            }
            cin.get(endline_char);
        }
        //solve maze
        //find start
        bool found = false;
        for(y = 0; (y < rs) && (found == false); y++)
        {
            for(x =0; x< cs; x++)
            {
                if(maze[y][x] == 'Z')
                {
                    found = true;
                    y--;
                    break;

                }
            }
        }
        //traverse maze
        traverse_maze(maze, y, x);

        //print maze
        cout << "Map : " << mazes_solved++ << endl;
        for(int k =0; k < rs; k++)
        {
            for(int j = 0; j<cs; j++)
            {
                cout << maze[k][j];
            }
            cout << endl;
        }

        //deallocate maze
        for(int k=0; k<rs; k++)
        {
            delete [] maze[k];
        }
        delete [] maze;

    }while(true); //break loop

    return 0;
}