
#include <iostream>
#include <limits>
#include <ctime>

class Player
{
    private:
        std::string name;
        int selection;
        int wins;
        int losses;

    public:
        Player(std::string name)
        {
            this->name = name;
        }

         virtual void makeSelection() = 0;

        /*
        Player operator++()
        {
            ++wins;

            return *this;
        }

        Player operator--()
        {
            ++losses;

            return *this;
        }
        */


        int getSelection() { return selection;}
        std::string getName() { return name;}

        void setSelection(int s) { selection = s;}



};

class Human: public Player
{
    public:
        Human(std::string name):
            Player(name)
        {

        }

        virtual void makeSelection()
        {
            int sel;
            std::cout<<"\n"<<getName()<<" Choose from the following: \n1.Rock \n2.Paper \n3.Scissors";
            std::cin>>sel;

            while (sel < 1 || sel > 3)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nInvalid input!";
                std::cout<<"\nChoose from the following: \n1.Rock \n2.Paper \n3.Scissors";
                std::cin>>sel;
            }

            setSelection(sel);
        }




};

class Computer: public Player
{
    public:
        Computer(std::string n) : Player(n) { };

        virtual void makeSelection()
        {
            srand(time(NULL));
            setSelection( (rand() %3) + 1 );
        }

};


int playGame(Player& p1, Player& p2);

int main()
{
    int winOrLose;
    int playerSelection;
    int again;
    int player1Wins = 0;
    int player1Losses = 0;
    int player2Wins = 0;
    int player2Losses = 0;

        std::cout<<"\n(: Welcome to rock paper scissors Game :)";
        std::cout<<"\n----------------------------------------";


        std::cout<<"\nHow do you want to play this game?";
        std::cout<<"\n1.Human vs Human";
        std::cout<<"\n2.Human vs Computer";
        std::cout<<"\n3.Computer vs Computer";
        std::cin>>playerSelection;

        while (playerSelection < 1 || playerSelection > 3)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nInvalid input! you have to select a number from 1 to 3";
            std::cin>>playerSelection;
        }

            if (playerSelection == 1)
            {
                std::string name1;
                std::string name2;

                std::cin.ignore(1000, '\n');

                std::cout<<"\nEnter player1 name:  ";
                getline(std::cin, name1);

                std::cout<<"\nEnter player2 name:  ";
                getline(std::cin, name2);


                Human player1(name1);
                Human player2(name2);

                while (again != 2)
                {


                    winOrLose = playGame(player1,player2);

                    if (winOrLose == 1)
                    {
                        player1Wins++;
                        player2Losses++;
                    }
                    else if (winOrLose == 2)
                    {
                        player2Wins++;
                        player1Losses++;
                    }

                    std::cout<<"\n"<<player1.getName()<<" has "<<player1Wins<<" wins and "<<player1Losses<<" losses";
                    std::cout<<"\n"<<player2.getName()<<" has "<<player2Wins<<" wins and "<<player2Losses<<" losses";
                    std::cout<<"\nWould you like to play again?";
                    std::cin>>again;

                    while (again < 1 || again > 2)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"\nInvalid input! enter 1 for yes or 2 for no";
                        std::cout<<"\nWould you like to play again?";
                        std::cin>>again;
                    }
                }
            }
            else if (playerSelection == 2)
            {


                    std::string name;

                    Computer player1("AI");

                    std::cin.ignore(1000, '\n');

                    std::cout<<"\nEnter your name:  ";
                    getline(std::cin, name);

                    Human player2(name);

                while (again !=2)
                {

                    winOrLose = playGame(player1,player2);



                    if (winOrLose == 1)
                    {
                        player1Wins++;
                        player2Losses++;
                    }
                    else if (winOrLose == 2)
                    {
                        player2Wins++;
                        player1Losses++;
                    }

                    std::cout<<"\n"<<player1.getName()<<" has "<<player1Wins<<" wins and "<<player1Losses<<" losses";
                    std::cout<<"\n"<<player2.getName()<<" has "<<player2Wins<<" wins and "<<player2Losses<<" losses";
                    std::cout<<"\nWould you like to play again?";
                    std::cin>>again;

                    while (again < 1 || again > 2)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"\nInvalid input! enter 1 for yes or 2 for no";
                        std::cout<<"\nWould you like to play again?";
                        std::cin>>again;
                    }
                }
            }
            else
            {

                    Computer player1("AI-0");
                    Computer player2("AI-1");

                while (again != 2)
                {

                    playGame(player1,player2);

                    if (winOrLose == 1)
                    {
                        player1Wins++;
                        player2Losses++;
                    }
                    else if (winOrLose == 2)
                    {
                        player2Wins++;
                        player1Losses++;
                    }

                    std::cout<<"\n"<<player1.getName()<<" has "<<player1Wins<<" wins and "<<player1Losses<<" losses";
                    std::cout<<"\n"<<player2.getName()<<" has "<<player2Wins<<" wins and "<<player2Losses<<" losses";
                    std::cout<<"\nWould you like to play again(1.Yes , 2.No)?";
                    std::cin>>again;

                    while (again < 1 || again > 2)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"\nInvalid input! enter 1 for yes or 2 for no";
                        std::cout<<"\nWould you like to play again?";
                        std::cin>>again;
                    }


                }
            }










}

int playGame(Player& p1, Player& p2)
{
    int win = 0;
    std::string selection1;
    std::string selection2;


    p1.makeSelection();
    p2.makeSelection();

    if ( p1.getSelection() == 1)
        selection1 = "Rock";
    else if ( p1.getSelection() == 2)
        selection1 = "Paper";
    else if ( p1.getSelection() == 3)
        selection1 = "Scissors";


    if ( p2.getSelection() == 1)
        selection2 = "Rock";
    else if ( p2.getSelection() == 2)
        selection2 = "Paper";
    else if ( p2.getSelection() == 3)
        selection2 = "Scissors";


    std::cout<<"\n"<<p1.getName()<<" selected "<<selection1<<" and "<<p2.getName()<<" selected "<<selection2;

    if (p1.getSelection() == 1 && p2.getSelection() == 2)
        {
            std::cout<<"\n:) "<<p2.getName()<<" won the game (:";
            win = 2;
        }
    else if (p1.getSelection() == 1 && p2.getSelection() == 3)
        {
            std::cout<<"\n:) "<<p1.getName()<<" won the game (:";
            win = 1;
        }
    else if (p1.getSelection() == 2 && p2.getSelection() == 1)
        {
            std::cout<<"\n:) "<<p1.getName()<<" won the game (:";
            win = 1;

        }
    else if (p1.getSelection() == 2 && p2.getSelection() == 3)
        {
            std::cout<<"\n:) "<<p2.getName()<<" won the game (:";
            win = 2;

        }
    else if (p1.getSelection() == 3 && p2.getSelection() == 1)
        {
            std::cout<<"\n:) "<<p2.getName()<<" won the game (:";
            win = 2;
        }
    else if (p1.getSelection() == 3 && p2.getSelection() == 2)
        {
            std::cout<<"\n:) "<<p1.getName()<<" won the game (:";
            win = 1;
        }
    else
        std::cout<<"\n:) Its a draw (:";



    return win;

}
