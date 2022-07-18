/*

Assignment:
-----------

CH16 #9: The goal for this project is to create a simple two-dimensional predator-prey simulation.
In this simulation the prey are ants and the predators are doodlebugs.
These critters live in a world composed of a 20 × 20 grid of cells.
Only one critter may occupy a cell at a time.
The grid is  enclosed, so a critter is not allowed to move off the edges of the world.
Time is simulated in time steps. Each critter performs some action every time step.

The ants behave according to the following model:
- Move.
    Every time step, randomly try to move up, down, left, or right.
    If the neighboring cell in the selected direction is occupied or would move the ant off the grid,
    then the ant stays in the current cell.
- Breed.
    If an ant survives for three time steps, then at the end of the time step (that is; after moving) the ant will breed.
    This is simulated by creating a new ant in an adjacent (up, down, left, or right) cell that is empty.
    If there is no empty cell available, then no breeding occurs.
    Once an off-spring is produced, an ant cannot produce an offspring until three more time steps have elapsed.

The doodlebugs behave according to the following model:
- Move.
    Every time step, if there is an adjacent ant (up, down, left, or right),
    then the doodlebug will move to that cell and eat the ant.
    Otherwise, the doodlebug moves according to the same rules as the ant.
    Note that a doodlebug cannot eat other doodlebugs.
- Breed.
    If a doodlebug survives for eight time steps,
    then at the end of the time step it will spawn off a new doodlebug in the same manner as the ant.
- Starve.
    If a doodlebug has not eaten an ant within the last three time steps,
    then at the end of the third time step it will starve and die.
    The doodlebug should then be removed from the grid of cells.

During one turn, all the doodlebugs should move before the ants do.

Write a program to implement this simulation
and draw the world using ASCII characters of “o” for an ant and “X” for a doodlebug or "-" for an empty space.

Create a class named Organism that encapsulates basic data common to both ants and doodlebugs.
This class should have a virtual function named move that is defined in the derived classes of Ant and Doodlebug.
You may need additional data structures to keep track of which critters have moved.

Initialize the world with 5 doodlebugs and 100 ants.
After each time step, prompt the user to press Enter to move to the next time step.

You should see a cyclical pattern between the population of predators and prey, although random perturbations may lead to the elimination of one or both species.

*/

#include <iostream>
#include <vector>
using namespace std;

//-------------------------CONSTANTS-------------------------//
// Board Dimensions
const int X_DIMENSION = 20;
const int Y_DIMENSION = 20;
const int BOARD_SIZE = 20;
// Board Characters
const char GRASS = '-';
const char DOODLEBUG = 'X';
const char ANT = 'o';
// Initial Number of Critters
const int INIT_DOODLEBUGS = 5;
const int INIT_ANTS = 100;
// Movement Directions
const int NO_GRASS = -2;
const int NO_ANT = -1;
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int LEFT = 4;
// Starving Doodlebugs
const int DOODLEBUG_IS_NOT_STARVING = 0;
const int DOODLEBUG_IS_STARVING = 1;
const int DOODLEBUG_NEEDS_TO_DIE = 3;
// Critters Breed
const int NEEDS_TO_BREED = 0;
const int BREED_ANTS = 3;
const int BREED_DOODLEBUGS = 8;
//-------------------------CONSTANTS-------------------------//

//--------------------------CLASSES--------------------------//
class Critter
{
protected:
    int m_x, m_y;
    int m_time_step;

public:
    Critter() : m_x(0), m_y(0), m_time_step(0) {}
    Critter(int x, int y) : m_x(x), m_y(x), m_time_step(0) {}
    
    // Set X & Y Coordinates
    void SetX(int x)
    { m_x = x; }
    void SetY(int y)
    { m_y = y; }

    // Get X & Y Coordinates
    const int& GetX() const
    { return m_x; }
    const int& GetY() const
    { return m_y; }

    // // Print X & Y Coordinates
    // virtual void GetXYPosition()
    // { cout << "Critter's Position: " << m_x << ", " << m_y << endl; }

    // TimeStep
    void UpdateTimeStep()
    { m_time_step++; }
    // void PrintTimeStep()
    // { cout << "TimeStep: " << m_time_step << endl; }
    const int& GetTimeStep()
    { return m_time_step; }

    // Move Critter
    virtual void Move() {}
};

class Doodlebug : public Critter
{
private:
    bool m_eat_ant = false;
    int m_ate_ants = 0;
    int m_starving_days = 0;

public:
    Doodlebug(){}
    Doodlebug(int x, int y) : Critter(x, y) {}

    // Doodlebug Eats Ants
    void SetEatAnt(bool yes_or_no)
    { m_eat_ant = yes_or_no; }
    const bool& GetEatAnt()
    { return m_eat_ant; }
    // void PrintEatAnt()
    // {
    //     if (m_eat_ant)
    //     { cout << "Bug ate the ant!" << endl; }
    //     else if (!m_eat_ant)
    //     { cout << "Bug did not eat an ant!" << endl; }
    // }
    
    // Doodlebug Starves
    void SetStarvingDays(int num)
    {
        if (num == DOODLEBUG_IS_NOT_STARVING)
        {
            m_starving_days = DOODLEBUG_IS_NOT_STARVING;
        }
        else if (num == DOODLEBUG_IS_STARVING)
        {
            m_starving_days += DOODLEBUG_IS_STARVING; 
        }  
    }

    const int& GetStarvingDays()
    { return m_starving_days; }

    // void PrintStarvingDays()
    // { cout << "Bug has been starving for this many days: " << m_starving_days << endl; }

    // virtual void GetXYPosition() override
    // { cout << "Bug's Position: " << m_x << ", " << m_y << endl; }

    virtual void Move(int direction)
    {
        if (direction == UP) 
        { 
            // cout << "Moving UP!" << endl;
            m_y -= 1;
        }
        else if (direction == DOWN)
        { 
            // cout << "Moving DOWN!" << endl;
            m_y += 1;
        }
        else if (direction == RIGHT)
        {
            // cout << "Moving RIGHT!" << endl;
            m_x += 1;
        }
        else if (direction == LEFT) 
        { 
            // cout << "Moving LEFT!" << endl;
            m_x -= 1;
        }  
    }
};

class Ant : public Critter
{   
public:
    Ant(){}
    Ant(int x, int y) : Critter(x, y) {}

    // virtual void GetXYPosition() override
    // { cout << "Ant's Position: " << m_x << ", " << m_y << endl; }

    virtual void Move(int direction)
    {
        if (direction == UP) 
        { 
            // cout << "Moving UP!" << endl;
            m_y -= 1;
        }
        else if (direction == DOWN)
        { 
            // cout << "Moving DOWN!" << endl;
            m_y += 1;
        }
        else if (direction == RIGHT)
        {
            // cout << "Moving RIGHT!" << endl;
            m_x += 1;
        }
        else if (direction == LEFT) 
        { 
            // cout << "Moving LEFT!" << endl;
            m_x -= 1;
        }  
    }
};
//--------------------------CLASSES--------------------------//

//--------------------FUNCTION PROTOTYPES--------------------//
// Board
void init_board(char board[X_DIMENSION][Y_DIMENSION]);
void print_board(char board[X_DIMENSION][Y_DIMENSION]);
void generate_random_xy_pair(char board[X_DIMENSION][Y_DIMENSION], int& x, int&y);

// Critters List
vector<Doodlebug> init_doodlebugs(char board[X_DIMENSION][Y_DIMENSION]);
vector<Ant> init_ants(char board[X_DIMENSION][Y_DIMENSION]);

// Move Critters
int find_grass(char board[X_DIMENSION][Y_DIMENSION], Critter& critter);
int find_ant(char board[X_DIMENSION][Y_DIMENSION], Doodlebug& bug);
void move_doodlebugs(char board[X_DIMENSION][Y_DIMENSION], vector<Doodlebug>& bugs);
void move_ants(char board[X_DIMENSION][Y_DIMENSION], vector<Ant>& ants);

// Update Time Step for Critters
void update_ant_TS(char board[X_DIMENSION][Y_DIMENSION], vector<Ant>& ants);
void update_bug_TS(char board[X_DIMENSION][Y_DIMENSION], vector<Doodlebug>& bugs);

void find_and_kill_starving_doodlebugs(char board[X_DIMENSION][Y_DIMENSION], vector<Doodlebug>& bugs);

// Breed Critters
void breed_ants(char board[X_DIMENSION][Y_DIMENSION], vector<Ant>& ants);
void breed_doodlebugs(char board[X_DIMENSION][Y_DIMENSION], vector<Doodlebug>& bugs);
//--------------------FUNCTION PROTOTYPES--------------------//

//---------------------------MAIN----------------------------//
int main()
{
    srand(time(0));
    /***********************************************/
    /*****************INITIALIZING******************/
    /***********************************************/
    // BOARD
    char board[X_DIMENSION][Y_DIMENSION];
    init_board(board);
    // DOODLEBUGS
    vector<Doodlebug> bugs = init_doodlebugs(board);
    // ANTS
    vector<Ant> ants = init_ants(board);

    cout << "*********************" << endl;
    cout << "* It's a Bug's Life *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    print_board(board);
    cout << "\nPress enter to continue: ";

    while(cin.get() == '\n')
    {
        /*******************/
        /*DOODLEBUGS MOVING*/
        /*******************/
        move_doodlebugs(board, bugs);
        update_bug_TS(board, bugs);
        find_and_kill_starving_doodlebugs(board, bugs);
        breed_doodlebugs(board, bugs);
        // cout << "\nAnts turn: " << endl;
        // cout << endl;
        // print_board(board);

        /*************/
        /*ANTS MOVING*/
        /*************/
        move_ants(board, ants);
        update_ant_TS(board, ants);
        breed_ants(board, ants);
        // cout << "\nDoodlebugs turn: " << endl;
        
        cout << endl;
        print_board(board);
        cout << "\nPress enter to continue: ";
    }

    return 0;
}
//---------------------------MAIN----------------------------//

//-------------------------FUNCTIONS-------------------------//
void init_board(char board[X_DIMENSION][Y_DIMENSION])
{
    for (int y = 0; y < Y_DIMENSION; y++)
    {
        for (int x = 0; x < X_DIMENSION; x++)
        {
            board[x][y] = GRASS;
        }
    }
}
void print_board(char board[X_DIMENSION][Y_DIMENSION])
{
    for (int y = 0; y < Y_DIMENSION; y++)
    {
        for (int x = 0; x < X_DIMENSION; x++)
        {
            cout << board[x][y];
        }
        cout << endl;
    }
}
void generate_random_xy_pair(char board[X_DIMENSION][Y_DIMENSION], int& x, int& y)
{
    do
    {
        x = rand() % X_DIMENSION;
        y = rand() % Y_DIMENSION;
    } while (board[x][y] != GRASS);
}

vector<Doodlebug> init_doodlebugs(char board[X_DIMENSION][Y_DIMENSION])
{
    vector<Doodlebug> bugs;                     // Create vector
    Doodlebug bug[INIT_DOODLEBUGS];             // Create bugs
    for (int b = 0; b < INIT_DOODLEBUGS; b++)   // Fill vector with bugs
    {
        int rand_x = 0;
        int rand_y = 0;
        generate_random_xy_pair(board, rand_x, rand_y);
        bug[b].SetX(rand_x);
        bug[b].SetY(rand_y);
        //bug[b].GetXYPosition();
        board[bug[b].GetX()][bug[b].GetY()] = DOODLEBUG;    // Set bug's position on board
        bugs.push_back(bug[b]);
    }
    return bugs;
}
vector<Ant> init_ants(char board[X_DIMENSION][Y_DIMENSION])
{
    vector<Ant> ants;                       // Create vector
    Ant ant[INIT_ANTS];                     // Create ants
    for (int a = 0; a < INIT_ANTS; a++)     // Fill vector with ants
    {
        int rand_x = 0;
        int rand_y = 0;
        generate_random_xy_pair(board, rand_x, rand_y);
        ant[a].SetX(rand_x);
        ant[a].SetY(rand_y);
        //ant[a].GetXYPosition();
        board[ant[a].GetX()][ant[a].GetY()] = ANT;    // Set ant's position on board
        ants.push_back(ant[a]);
    }
    return ants;
}

// Find Ant - Bugs Move to Eat Ants
int find_ant(char board[X_DIMENSION][Y_DIMENSION], Doodlebug& bug)
{
    int check_x = bug.GetX();
    int check_y = bug.GetY();

    int const LOOK_NORTH = check_y - 1;  // Check NORTH position: x does not change, shift y--
    int const LOOK_SOUTH = check_y + 1;  // Check SOUTH position: x does not change, shift y++ 
    int const LOOK_EAST = check_x + 1;   // Check EAST position: shift x++, y does not change
    int const LOOK_WEST = check_x - 1;   // Check WEST position: shift x--, y does not change

    // MAKE SURE COORDINATE SHIFTS STAY WITHIN BOUNDARIES OF THE BOARD!!!!!!!
    bool const NORTH_BOUNDARY = (LOOK_NORTH >= 0 && LOOK_NORTH < BOARD_SIZE);
    bool const EAST_BOUNDARY = (LOOK_EAST >= 0 && LOOK_EAST < BOARD_SIZE);
    bool const SOUTH_BOUNDARY = (LOOK_SOUTH >= 0 && LOOK_SOUTH < BOARD_SIZE);
    bool const WEST_BOUNDARY = (LOOK_WEST >= 0 && LOOK_WEST < BOARD_SIZE);

    if (NORTH_BOUNDARY && board[check_x][LOOK_NORTH] == ANT)
    {
        // cout << "Found ant NORTH!" << endl;
        return UP;
    }
    else if (EAST_BOUNDARY && board[LOOK_EAST][check_y] == ANT)
    {
        // cout << "Found ant EAST!" << endl;
        return RIGHT;
    }
    else if (SOUTH_BOUNDARY && board[check_x][LOOK_SOUTH] == ANT)
    {
        // cout << "Found ant SOUTH!" << endl;
        return DOWN;
    }
    else if (WEST_BOUNDARY && board[LOOK_WEST][check_y] == ANT)
    {
        // cout << "Found ant WEST!" << endl;
        return LEFT;
    }
    else
    {
        // cout << "No ant found!" << endl;
        return NO_ANT;
    }
}
// Find Grass - Critters Move to Lushes Grass
int find_grass(char board[X_DIMENSION][Y_DIMENSION], Critter& critter)
{
    int check_x = critter.GetX();
    int check_y = critter.GetY();

    int const LOOK_NORTH = check_y - 1;  // Check NORTH position: x does not change, shift y--
    int const LOOK_SOUTH = check_y + 1;  // Check SOUTH position: x does not change, shift y++ 
    int const LOOK_EAST = check_x + 1;   // Check EAST position: shift x++, y does not change
    int const LOOK_WEST = check_x - 1;   // Check WEST position: shift x--, y does not change

    // MAKE SURE COORDINATE SHIFTS STAY WITHIN BOUNDARIES OF THE BOARD!!!!!!!
    bool const NORTH_BOUNDARY = (LOOK_NORTH >= 0 && LOOK_NORTH < BOARD_SIZE);
    bool const EAST_BOUNDARY = (LOOK_EAST >= 0 && LOOK_EAST < BOARD_SIZE);
    bool const SOUTH_BOUNDARY = (LOOK_SOUTH >= 0 && LOOK_SOUTH < BOARD_SIZE);
    bool const WEST_BOUNDARY = (LOOK_WEST >= 0 && LOOK_WEST < BOARD_SIZE);

    // Generate Allowable Random Move Between 1 & 4    
    int rand_num = 0;
    int valid_move = 4;

    while(valid_move >= 0)
    {
        rand_num = rand() % 4 + 1;  
        
        if (rand_num == UP && NORTH_BOUNDARY && board[check_x][LOOK_NORTH] == GRASS)            // Move North
        {
            //cout << "Found grass NORTH!" << endl;
            return UP;
        }
        else if (rand_num == RIGHT && EAST_BOUNDARY && board[LOOK_EAST][check_y] == GRASS)      // Move East
        {
            //cout << "Found grass EAST!" << endl;
            return RIGHT;
        }
        else if (rand_num == DOWN && SOUTH_BOUNDARY && board[check_x][LOOK_SOUTH] == GRASS)     // Move South
        {
            //cout << "Found grass SOUTH!" << endl;
            return DOWN;
        }
        else if (rand_num == LEFT && WEST_BOUNDARY && board[LOOK_WEST][check_y] == GRASS)       // Move West
        {
            //cout << "Found grass WEST!" << endl;
            return LEFT;
        }
        valid_move--;
    }
    // cout << "No grass found!" << endl;
    return NO_GRASS;
}

void move_doodlebugs(char board[X_DIMENSION][Y_DIMENSION], vector<Doodlebug>& bugs)
{
    // cout << "************" << endl;
    // cout << "MOVING BUGS:" << endl;
    // cout << "************" << endl;
    for (Doodlebug& bug : bugs)
    {
        if (board[bug.GetX()][bug.GetY()] == DOODLEBUG)
        {
            // cout << "---------" << endl;
            // cout << "NEW BUG #" << endl;
            // cout << "---------" << endl;
            // print_board(board);
            /*********************************************************************/
            /************************LOOKING FOR ANT******************************/
            /*********************************************************************/
            int ant_direction = find_ant(board, bug);
            if (ant_direction != NO_ANT)
            {   // Bug is going to eat the ant!
                bug.SetEatAnt(true);
                
                int bugs_x = bug.GetX();
                int bugs_y = bug.GetY();
                
                // cout << "\nOld ";
                // bug.GetXYPosition();
                board[bug.GetX()][bug.GetY()] = GRASS;      // Reset bug's old position back to grass
                bug.Move(ant_direction);                    // Move bug to the ant's position
                board[bug.GetX()][bug.GetY()] = DOODLEBUG;  // Set board to bug's new position
                // cout << "New ";
                // bug.GetXYPosition();
                // bug.PrintEatAnt();
            }
            /***********************************************************************/
            /************************LOOKING FOR GRASS******************************/
            /***********************************************************************/
            else if (ant_direction == NO_ANT)
            {   // Bug is NOT going to eat any ants :(
                bug.SetEatAnt(false);

                int grass_direction = find_grass(board, bug);
                if (grass_direction != NO_GRASS)
                {
                    // cout << "\nOld ";
                    // bug.GetXYPosition();
                    board[bug.GetX()][bug.GetY()] = GRASS;      // Reset bug's old position back to grass
                    bug.Move(grass_direction);                  // Move bug to lushes grass positition
                    board[bug.GetX()][bug.GetY()] = DOODLEBUG;  // Set board to bug's position
                    // cout << "New ";
                    // bug.GetXYPosition();
                }
                else if (grass_direction == NO_GRASS)
                {
                    // cout << "\nOld ";
                    // bug.GetXYPosition();                        // Bug stays in current position
                    // cout << "Bug did NOT move and is staying in the ";
                    // bug.GetXYPosition();
                }
                // bug.PrintEatAnt();
            }
            // cout << endl;
        }
        // print_board(board);
        // cout << endl;
    }
}
void move_ants(char board[X_DIMENSION][Y_DIMENSION], vector<Ant>& ants)
{
    // cout << "************" << endl;
    // cout << "MOVING ANTS:" << endl;
    // cout << "************" << endl;
    for (Ant& ant : ants)
    {
        if (board[ant.GetX()][ant.GetY()] == ANT)
        {
            // cout << "---------" << endl;
            // cout << "NEW ANT #" << endl;
            // cout << "---------" << endl;
            // print_board(board);
            int grass_direction = find_grass(board, ant);
            if (grass_direction != NO_GRASS)
            {
                // cout << "\nOld ";
                // ant.GetXYPosition();
                board[ant.GetX()][ant.GetY()] = GRASS;          // Reset ant's old position back to grass
                ant.Move(grass_direction);                      // Move ant to lushes grass positition
                board[ant.GetX()][ant.GetY()] = ANT;            // Set board to ant's position
            }
            else if (grass_direction == NO_GRASS)
            {
                // cout << "\nOld ";
                // ant.GetXYPosition();                            // Ant stays in current position
                // cout << "Ant did NOT move and is staying in the ";
                // ant.GetXYPosition();
                // cout << endl;
            }
        }
    }
    // print_board(board);
    // cout << endl;
}

// Update Time Steps
void update_ant_TS(char board[X_DIMENSION][Y_DIMENSION], vector<Ant>& ants)
{
    for (Ant& ant : ants)
    {
        if (board[ant.GetX()][ant.GetY()] == ANT)
        {
            ant.UpdateTimeStep();
            //ant.PrintTimeStep();
        }
    }
}
void update_bug_TS(char board[X_DIMENSION][Y_DIMENSION], vector<Doodlebug>& bugs)
{
    for (Doodlebug& bug : bugs)
    {
        if (board[bug.GetX()][bug.GetY()] == DOODLEBUG)
        {
            bug.UpdateTimeStep();
            // bug.PrintTimeStep();
        }
    }
}

// Find Starving Doodlebugs
void find_and_kill_starving_doodlebugs(char board[X_DIMENSION][Y_DIMENSION], vector<Doodlebug>& bugs)
{
    for (Doodlebug& bug : bugs)
    {
        if (board[bug.GetX()][bug.GetY()] == DOODLEBUG)
        {
            if (bug.GetEatAnt() == true)
            {
                bug.SetStarvingDays(DOODLEBUG_IS_NOT_STARVING);
            }
            else if (bug.GetEatAnt() == false)
            {
                bug.SetStarvingDays(DOODLEBUG_IS_STARVING);
            }
            // At the end of 3 timesteps, if a bug has not eaten an ant, bug starves and dies
            if (bug.GetStarvingDays() >= DOODLEBUG_NEEDS_TO_DIE)
            {
                board[bug.GetX()][bug.GetY()] = GRASS;  // Reset bug's old position back to grass
            }
            // bug.PrintEatAnt();
            // bug.PrintStarvingDays();
        } 
    }
}

void breed_doodlebugs(char board[X_DIMENSION][Y_DIMENSION], vector<Doodlebug>& bugs)
{
    for (Doodlebug bug : bugs)
    {
        if (board[bug.GetX()][bug.GetY()] == DOODLEBUG)
        {
            if (bug.GetTimeStep() % BREED_DOODLEBUGS == NEEDS_TO_BREED)
            {
                int breed_x = bug.GetX();
                int breed_y = bug.GetY();
                
                int const BREED_UP = breed_y - 1;       // Check NORTH position: x does not change, shift y--
                int const BREED_DOWN = breed_y + 1;     // Check SOUTH position: x does not change, shift y++ 
                int const BREED_RIGHT = breed_x + 1;    // Check EAST position: shift x++, y does not change
                int const BREED_LEFT = breed_x - 1;     // Check WEST position: shift x--, y does not change
                
                int breed_direction = find_grass(board, bug);
                
                if (breed_direction == UP)
                { breed_y = BREED_UP; }
                
                else if (breed_direction == RIGHT)
                { breed_x = BREED_RIGHT; }
                
                else if (breed_direction == DOWN)
                { breed_y = BREED_DOWN; }
                
                else if (breed_direction == LEFT)
                { breed_x = BREED_LEFT; }
                    
                Doodlebug baby_bug(breed_x, breed_y);
                bugs.push_back(baby_bug);
                board[baby_bug.GetX()][baby_bug.GetY()] = DOODLEBUG;
            }
        }
    }
}
void breed_ants(char board[X_DIMENSION][Y_DIMENSION], vector<Ant>& ants)
{
    for (Ant ant : ants)
    {
        if (board[ant.GetX()][ant.GetY()] == ANT)
        {
            if (ant.GetTimeStep() % BREED_ANTS == NEEDS_TO_BREED)
            {
                int breed_x = ant.GetX();
                int breed_y = ant.GetY();
                
                int const BREED_UP = breed_y - 1;       // Check NORTH position: x does not change, shift y--
                int const BREED_DOWN = breed_y + 1;     // Check SOUTH position: x does not change, shift y++ 
                int const BREED_RIGHT = breed_x + 1;    // Check EAST position: shift x++, y does not change
                int const BREED_LEFT = breed_x - 1;     // Check WEST position: shift x--, y does not change
                
                int breed_direction = find_grass(board, ant);
                
                if (breed_direction == UP)
                { breed_y = BREED_UP; }
                
                else if (breed_direction == RIGHT)
                { breed_x = BREED_RIGHT; }
                
                else if (breed_direction == DOWN)
                { breed_y = BREED_DOWN; }
                
                else if (breed_direction == LEFT)
                { breed_x = BREED_LEFT; }
                    
                Ant baby_ant(breed_x, breed_y);
                ants.push_back(baby_ant);
                board[baby_ant.GetX()][baby_ant.GetY()] = ANT;
            }
        }
    }
}