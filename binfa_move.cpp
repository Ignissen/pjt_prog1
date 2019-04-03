#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define null NULL

class Binfa
{
private:
	class Node
	{
	public:
		Node(char c='/')
		{
			this->c=c;
			this->left = null;
			this->right = null;
		}
		char c;
		Node* left;
		Node* right;
	};
	Node* fa;
	
    Node *  masol ( Node * elem, Node * regifa ) {

          Node * ujelem = NULL;

          if ( elem != NULL ) {
               ujelem = new Node ( elem->c );

               ujelem->left =  masol  (elem->left, regifa ) ;
               ujelem->right =  masol  (elem->right, regifa );

               if ( regifa == elem )
                    fa = ujelem;

          }

          return ujelem;
     }

public:
	Binfa(): fa(&gyoker)
	{

	}
	
    Binfa ( const Binfa & regi ) 
    {
        std::cout << "LZWBinFa copy ctor" << std::endl;

        gyoker.left =  masol ( regi.gyoker.left, regi.fa ) ;
        gyoker.right =  masol ( regi.gyoker.right, regi.fa ) ;

        if ( regi.fa == & ( regi.gyoker ) )
            fa = &gyoker;

     }
    
    Binfa ( Binfa && regi )
    {
        std::cout << "LZWBinFa move ctor" << std::endl;

        gyoker.left = regi.gyoker.left;
        gyoker.right = regi.gyoker.right;

        regi.gyoker.left =   nullptr ;
        regi.gyoker.right =  nullptr ;

    }

    Binfa& operator= ( const Binfa & regi ) 
    {
        std::cout << "LZWBinFa copy ctor" << std::endl;

        gyoker.left =  masol ( regi.gyoker.left, regi.fa ) ;
        gyoker.right =  masol ( regi.gyoker.right, regi.fa ) ;

        if ( regi.fa == & ( regi.gyoker ) )
            fa = &gyoker;

    }

    Binfa& operator= (Binfa && regi ) 
    {
        std::cout << "LZWBinFa move ctor" << std::endl;

        gyoker.left = regi.gyoker.left;
        gyoker.right = regi.gyoker.right;

        regi.gyoker.left =   nullptr ;
        regi.gyoker.right =  nullptr ;

    }

	void operator<<(char c)
	{
		if(c=='0')
		{
			if(fa->left == null)
			{
				fa->left = new Node('0');
				fa = &gyoker;
			}
			else
			{
				fa = fa->left;
			}
		}
		else
		{
			if(fa->right == null)
			{
				fa->right = new Node('1');
				fa = &gyoker;
			}
			else
			{
				fa = fa->right;
			}
		}
	}
	
	void preorder(Node* elem,int depth=0)
	{
		if(elem==null)
		{
			return;
		}
		if(depth) 
		{
			char *spaces;
			spaces =(char*) malloc(sizeof(char)*depth*2+1);
			for(int i=0;i<depth;i+=2)
			{
				spaces[i]='-';
				spaces[i+1]='-';
			}
			spaces[depth*2]='\0';

			printf("%s%c\n",spaces,elem->c);
		}
		else
		{
			printf("%c\n",elem->c);
		}
		preorder(elem->left,depth+1);	
		preorder(elem->right,depth+1);
	}

	void inorder(Node* elem,int depth=0)
	{
		if(elem==null)
		{
			return;
		}
		inorder(elem->left,depth+1);
		if(depth) 
		{
			char *spaces;
			spaces =(char*) malloc(sizeof(char)*depth*2+1);
			for(int i=0;i<depth;i+=2)
			{
				spaces[i]='-';
				spaces[i+1]='-';
			}
			spaces[depth*2]='\0';

			printf("%s%c\n",spaces,elem->c);
		}
		else
		{
			printf("%c\n",elem->c);
		}	
		inorder(elem->right,depth+1);
	}

	void postorder(Node* elem,int depth=0)
	{
		if(elem==null)
		{
			return;
		}
		postorder(elem->left,depth+1);
		postorder(elem->right,depth+1);
		if(depth) 
		{
			char *spaces;
			spaces =(char*) malloc(sizeof(char)*depth*2+1);
			for(int i=0;i<depth;i+=2)
			{
				spaces[i]='-';
				spaces[i+1]='-';
			}
			spaces[depth*2]='\0';

			printf("%s%c\n",spaces,elem->c);
		}
		else
		{
			printf("%c\n",elem->c);
		}	
	}

	void destroy_tree(Node* elem)
	{
		if(elem==null)
		{
			return;
		}
		destroy_tree(elem->left);
		destroy_tree(elem->right);
		if(elem->c!='/') delete elem;
	}

	Node gyoker;

};

void usage()
{
	printf("Használat: ./binfa KAPCSOLÓ\n");
	printf("Az KAPCSOLÓ lehet:\n");
	printf("--preorder\tA bináris fa preorder bejárása\n");
	printf("--inorder\tA bináris fa inorder bejárása\n");
	printf("--postorder\tA bináris fa postorder bejárása\n");
}

int main(int argc, char** argv)
{
	srand(time(0));
	Binfa bfa,bfa2;
	for(int i=0;i<100;i++)
	{
		int x=rand()%2;
		if(x)
		{
			bfa<<'1';
            bfa2<<'0';
		}
		else
		{
			bfa<<'0';
            bfa2<<'1';
		}
	}
	if(argc == 2)
	{
		if(strcmp(argv[1],"--preorder")==0)
		{
            std::cout<<"bfa"<<std::endl;
			bfa.preorder(&bfa.gyoker);
            std::cout<<"bfa2"<<std::endl;
            bfa2.preorder(&bfa.gyoker);
		}
		else if(strcmp(argv[1],"--inorder")==0)
		{
            std::cout<<"bfa"<<std::endl;
			bfa.inorder(&bfa.gyoker);
            std::cout<<"bfa2"<<std::endl;
            bfa2.inorder(&bfa.gyoker);
		}
		else if(strcmp(argv[1],"--postorder")==0)
		{
            std::cout<<"bfa"<<std::endl;
			bfa.postorder(&bfa.gyoker);
            std::cout<<"bfa2"<<std::endl;
            bfa2.postorder(&bfa.gyoker);
		}
		else
		{
			usage();
		}
	}
	else
	{
		usage();
	}

    bfa2=std::move(bfa);

    bfa2.preorder(&bfa2.gyoker);

	bfa.destroy_tree(&bfa.gyoker);
    bfa2.destroy_tree(&bfa.gyoker);
	return 0;
}