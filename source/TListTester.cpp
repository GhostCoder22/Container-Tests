#include <stdlib.h>
#include <stdio.h>

#include <Containers/TList.hxx>

bool TListWalk();


TList<const char*> list;

TNodeID TListAdd(const char* string)
{
  if (string == nullptr)
    printf("[TList::Add]: No string specified.\n");
  else
  {
    TNodeID result = list.Add(string);
    if (result == 0)
      printf("[TList::Add]: \'%s\' **ALLOCATION ERROR**\n", string);
    else
      printf("[%d]: \'%s\' **ADDED**\n", result, string);
    return result;
  }
  return 0;
}

TNodeID TListChange(const char* oldString, const char* newString)
{
  if (oldString == nullptr)
    printf("[TList::Change]: Old string not specified.\n");
  else
  if (newString == nullptr)
    printf("[TList::Change]: New string not specified.\n");
  else
  {
    TNodeID result = list.Change(oldString, newString);
    if (!result)
      printf("[TList::Change]: Error changing \'%s\' to \'%s\'\n", oldString, newString);
    else
    {
      printf("[TList::Change] \'%s\' changed to \'%s\'\n", oldString, newString);
      TListWalk();
      return result;
    }
  }
  return 0;
}

bool TListRemove(const char* string)
{
  if (string == nullptr)
    printf("[TList::Remove]: No string specified.\n");
  else
  {
    TNodeID result = list.Remove(string);
    if (!result)
      printf("[TList::Remove]: \'%s\' **NOT FOUND**\n", string);
    else
      printf("\'%s\' removed'\n", string);
    return result;
  }
  return false;
}

TNodeID TListSize()
{
  TNodeID n = list.Size();
  printf("[TList::Size]: List has \'%d\' elements.\n", n);
  return n;
}

bool TListFind(const char* string)
{
  if (string == nullptr)
    printf("[TList::Find]: No string specified.\n");
  else
  {
    TNode<const char*>** node = list.Find(string);
    if (!node)
      printf("[TList::Find]: \'%s\' **NOT FOUND**\n", string);
    else
      printf("[TList::Find][%d]: \'%s\' **FOUND**\n", (*node)->id, string);
    return true;
  }
  return false;
}

TNodeID TListNext(const char* string)
{
  if (string == nullptr)
    printf("[TList::Next]: No string specified.\n");
  else
  {
    TNode<const char*>** node = list.Next(string);
    if (!node)
      printf("[TList::Next]: \'%s\' **NOT FOUND**\n", string);
    else
      printf("[TList::Next][%d]: \'%s\' -> \'%s\'\n", (*node)->id, string, (*node)->data);
    return (*node)->id;
  }
  return false;
}

bool TListWalker(const char* string, TNodeID id, TNodeID pos)
{
  if (pos == 1)
    printf("[TList::Size]: List has \'%d\' elements.\n[TList::Walk]\n", list.Size());
  if (pos == 1)
    printf("HEAD ");
  else if (pos == list.Size())
    printf("TAIL ");
  else
    printf("     ");
  printf("[%d:%d]: %s\n", pos, id, string);
  if (pos == list.Size())
  {
    printf("\n");
    system("PAUSE");
    printf("\n");
  }
  return true;
}

bool TListWalk()
{
  return list.Walk(TListWalker);
}

int main(void)
{
  // Phase 1 test: Add
  TListAdd("Star Trek: Enterprise");
  TListAdd("Star Trek");
  TListAdd("Walker, Texas Ranger");
  TListAdd("Star Trek: The Next Generation");
  TListAdd("Star Trek: Deep Space Nine");
  TListAdd("Star Trek: Voyager");
  printf("\n");
  TListWalk();
  TListChange("Walker, Texas Ranger", "Walker Texas Ranger");

  // Phase 2 test: Remove
  TListRemove("Walker Texas Ranger");
  TListWalk();
  TListNext("Star Trek: Deep Space Nine");
  TListFind("Star Trek");
  TListFind("Walker Texas Ranger");
  TListFind("Star Trek: Voyager");
  TListSize();
  printf("\n");
  system("PAUSE");
  printf("\n");

  return 0;
}
