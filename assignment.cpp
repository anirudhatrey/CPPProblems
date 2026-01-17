#include <bits/stdc++.h>
using namespace std;
 
int countChar(string ch, char c)
{ int i,count=0;
    for(i=0;ch[i]!='\0';i++)
   {
       if(ch[i]==c)
            count++;
   } 
    return count;
}




void minimumCharactersForWords(int n, string arr[])
{  
    int i = 0;
    // array of all required letters
    char letters[100]={};
    // conter to keep updating length of array of letters
    int count=0;
    // checking existance of letters
    int flag=0;

// iterate through every word
  for (i; i < n; i++)
  {
      // Current word
        string st = arr[i];
       for (int j = 0; j < st.length(); j++) {  
     letters[count+1]=flag;
        char* end = letters + sizeof(letters) / sizeof(letters[0]);            
    char* position = std::find(letters, end, st[j]);
    if(position != end){
        position++;
        flag =countChar(st, st[j]);
        
        flag+=48;
  if(*position<flag){
      *position=flag;
  }

    }else{
        // add current character to the array of all the letters
  letters[count]=st[j];
        letters[count+1]=49;
        count+=2;  
    }
   
    }
  }
  
  for(int i=0;i<count;i++){
 i=i+1;
 for(int j=letters[i];j>48;j--)
 {
cout<<letters[i-1];
 }

  }
     return;
}
                                                                                                                                                                                                               

/* Driver code*/
int main()
{
    
  string words[] = {"this", "that", "did", "deed", "them!", "a"};
    int n = 6;
    cout << "minimum characters required for all these words are\n";
    minimumCharactersForWords(n,words);
   

}