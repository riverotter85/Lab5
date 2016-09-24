#include "SortedListLinked.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

void addCDs(ListArray<CD>* list, SortedListLinked<CD>* sll)
{
   ListArrayIterator<CD>* iter = list->iterator();

   //DO THIS
   //iterate over and add the cds to the list box (use lb->addItem)

   while (iter->hasNext()){
      sll->add(iter->next());
   }


   delete iter;
}

void deleteCDs(ListArray<CD>* list)
{
   //ListArrayIterator<CD>* iter = list->iterator();

   //DO THIS  
   //iterate over and delete the cds
   
   list->removeAll();



   //delete iter;
}

//DO THIS
int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");

   //DO THIS
   //create the sorted linked list
   
   SortedListLinked<CD> *sll = new SortedListLinked<CD>(&CD::compare_items);
   
   addCDs(cds, sll);
   
   
   ListLinkedIterator<CD>* iter = sll->iterator();
   
   while(iter->hasNext()){
      iter->next()->displayCD();
   }
   
   
   delete sll;
   deleteCDs(cds);


   return 0;
}
