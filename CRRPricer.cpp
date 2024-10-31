#include "CRRPricer.h"


//outils

int factorielle(int N)
{
    return 1;
}

int coefBin(int N, int k)
{
    return 1;
}


// Passage au CRRPricer

CRRPricer::CRRPricer(Option* option, int N, double asset_price, double U, double D, double rate) : option{ option }, depth{ N }, asset_price{ asset_price }, up{ U }, down{ D }, interest_rate{ rate } {}

void CRRPricer::myPriceTree()
{
    BinaryTree<double> tree = BinaryTree<double>(this->depth);
    std::cout << "Your Price tree (not option price) is : " << std::endl;
    for (int i = 0; i < (this->depth); i++)
    {
        for (int j = i; j > -1; j--)
        {
            tree.setNode(i + 1, i - j + 1, (this->asset_price) * pow(1 + this->up, j) * pow(1 + this->down, i - j));
        }
    }
    tree.display();
}


void CRRPricer::myOptionPriceTree()
{
    //Hull adapted
    double q = (exp(this->interest_rate * (this->option->getExpiry() / (this->depth - 1))) - (1 + this->down)) / ((1 + this->up) - (1 + this->down));
    BinaryTree<double> price_tree = BinaryTree<double>(this->depth);
    for (int i = 0; i < (this->depth); i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            price_tree.setNode(i + 1, j + 1, (this->asset_price) * pow(1 + this->up, j) * pow(1 + this->down, i - j));
        }
    }


    BinaryTree<double> option_tree = BinaryTree<double>(this->depth);
    for (int k = (this->depth) - 1; k > -1; k--)  //il faut commencer par la fin et aller à reculons
    {
        for (int l = 0; l < k + 1; l++)
        {
            if (k == ((this->depth) - 1)) //si on est sur le bout de l'arbre
            {
                option_tree.setNode(k + 1, l + 1, (this->option)->payoff(price_tree.getNode(k + 1, l + 1)));
            }

            else
            {
                //option_tree.setNode(k + 1, l + 1, (q * option_tree.getNode(k + 2, l + 2) + (1 - q) * option_tree.getNode(k + 2, l + 1)) / (1 + this->interest_rate));
                option_tree.setNode(k + 1, l + 1, exp(-this->interest_rate * (this->option->getExpiry() / (this->depth - 1))) * (q * option_tree.getNode(k + 2, l + 2) + (1 - q) * option_tree.getNode(k + 2, l + 1)));
            }
        }
    }
    std::cout << "Your Option price tree is : " << std::endl;
    option_tree.display();

}
double CRRPricer::operator()(bool closed_form) const
{

    double option_price = 0;
    double q = (exp(this->interest_rate * (this->option->getExpiry() / (this->depth - 1))) - (1 + this->down)) / ((1 + this->up) - (1 + this->down));
    BinaryTree<double> price_tree = BinaryTree<double>(this->depth);
    for (int i = 0; i < (this->depth); i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            price_tree.setNode(i + 1, j + 1, (this->asset_price) * pow(1 + this->up, j) * pow(1 + this->down, i - j));
        }
    }



    if (closed_form == false)
    {
        //Hull adapted
        BinaryTree<double> option_tree = BinaryTree<double>(this->depth);
        for (int k = (this->depth) - 1; k > -1; k--)  //il faut commencer par la fin et aller à reculons
        {
            for (int l = 0; l < k + 1; l++)
            {
                if (k == ((this->depth) - 1)) //si on est sur le bout de l'arbre
                {
                    option_tree.setNode(k + 1, l + 1, (this->option)->payoff(price_tree.getNode(k + 1, l + 1)));
                }

                else
                {
                    //option_tree.setNode(k + 1, l + 1, (q * option_tree.getNode(k + 2, l + 2) + (1 - q) * option_tree.getNode(k + 2, l + 1)) / (1 + this->interest_rate));
                    option_tree.setNode(k + 1, l + 1, exp(-this->interest_rate * (this->option->getExpiry() / (this->depth - 1))) * (q * option_tree.getNode(k + 2, l + 2) + (1 - q) * option_tree.getNode(k + 2, l + 1)));
                }
            }
        }

        option_price = (option_tree.getNode(1, 1));
    }

    else
    {
        double s = 0;
        for (int i = 0; i < (this->depth); i++)
        {
            s += coefBin(this->depth, i) * pow(q, i) * pow(1 - q, (this->depth) - i) * price_tree.getNode(this->depth, i + 1);
            option_price = s / (pow((1 + this->interest_rate), this->depth));
        }
    }

    return option_price;
}
