#include<iostream>
using namespace std;

struct node
{
        node *a[26];
        bool eos;
};

class trie
{
        node *root;
        
        public:
        
        trie()
        {
                node *pnode=new node();
                
                for(int i=0;i<26;++i)
                      pnode->a[i]=NULL;
                      
               pnode->eos=false;
                     
                root=pnode;              
                
        }
        
        node * getnode()
        {
                node *pnode=new node();
                
                for(int i=0;i<26;++i)
                     pnode->a[i]=NULL;
                      
                pnode->eos=false;
                     
                return pnode;  
        } 
        
        void insert(string);  
        bool search(string);      
};

void trie::insert(string key)
{
        node *pcrawl=root;
        
        for(int i=0;i<key.length();++i)
        {
                if(!pcrawl->a[key[i]-'a'])
                pcrawl->a[key[i]-'a']=getnode();
                
                pcrawl=pcrawl->a[key[i]-'a'];
        }
        pcrawl->eos=true;
}
bool trie::search(string key)
{
        node*pcrawl=root;
        
        for(int i=0;i<key.length();++i)
        {
                if(!pcrawl->a[key[i]-'a'])
                return false;
                
                pcrawl=pcrawl->a[key[i]-'a'];
        }
        
        return (pcrawl->eos&&pcrawl!=NULL);
        
}
int main()
{
        string keys[]={"the","moon","is","bright"};
        
        trie t;
        
        for(int i=0;i<4;++i)
        t.insert(keys[i]);
        
        cout<<t.search("the")<<"\n";
        
        cout<<t.search("talk")<<"\n";
        
         cout<<t.search("moon")<<"\n";
         
          cout<<t.search("is")<<"\n";
          
           cout<<t.search("bright")<<"\n";
        
}
