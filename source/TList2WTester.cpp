#include <stdlib.h>
#include <stdio.h>

#include <Containers/TList.hxx>

bool TList2WWalk();

TList2W<const char*> list2W;

TNodeID TList2WAdd(const char* string)
{
  if (string == nullptr)
    printf("[TList2W::Add]: No string specified.\n");
  else
  {
    TNodeID result = list2W.Add(string);
    if (result == 0)
      printf("[TList2W::Add]: \'%s\' **ALLOCATION ERROR**\n", string);
    else
      printf("[%d]: \'%s\' **ADDED**\n", result, string);
    return result;
  }
  return 0;
}

TNodeID TList2WChange(const char* oldString, const char* newString)
{
  if (oldString == nullptr)
    printf("[TList2W::Change]: Old string not specified.\n");
  else
  if (newString == nullptr)
    printf("[TList2W::Change]: New string not specified.\n");
  else
  {
    TNodeID result = list2W.Change(oldString, newString);
    if (!result)
      printf("[TList2W::Change]: Error changing \'%s\' to \'%s\'\n", oldString, newString);
    else
    {
      printf("[TList2W::Change] \'%s\' changed to \'%s\'\n", oldString, newString);
      TList2WWalk();
      return result;
    }
  }
  return 0;
}

bool TList2WRemove(const char* string)
{
  if (string == nullptr)
    printf("[TList2W::Remove]: No string specified.\n");
  else
  {
    TNodeID result = list2W.Remove(string);
    if (!result)
      printf("[TList2W::Remove]: \'%s\' **NOT FOUND**\n", string);
    else
      printf("\'%s\' removed'\n", string);
    return result;
  }
  return false;
}

TNodeID TList2WSize()
{
  TNodeID n = list2W.Size();
  printf("[TList2W::Size]: List has \'%d\' elements.\n", n);
  return n;
}

bool TList2WFind(const char* string)
{
  if (string == nullptr)
    printf("[TList2W::Find]: No string specified.\n");
  else
  {
    TNode2W<const char*>** node = list2W.Find(string);
    if (!node)
      printf("[TList2W::Find]: \'%s\' **NOT FOUND**\n", string);
    else
      printf("[TList2W::Find][%d]: \'%s\' **FOUND**\n", (*node)->id, string);
    return true;
  }
  return false;
}


bool TList2WWalker(const char* string, TNodeID id, TNodeID pos)
{
  if (pos == 1)
    printf("[TList2W::Size]: List has \'%d\' elements.\n[TList2W::Walk]\n", list2W.Size());
  if (pos == 1)
    printf("HEAD ");
  else if (pos == list2W.Size())
    printf("TAIL ");
  else
    printf("     ");
  printf("[%d:%d]: %s\n", pos, id, string);
  if (pos == list2W.Size())
  {
    printf("\n");
    system("PAUSE");
    printf("\n");
  }
  return true;
}

TNodeID TList2WNext(const char* string)
{
  if (string == nullptr)
    printf("[TList2W::Next]: No string specified.\n");
  else
  {
    TNode2W<const char*>** node = list2W.Next(string);
    if (!node)
      printf("[TList2W::Next]: \'%s\' **NOT FOUND**\n", string);
    else
      printf("[TList2W::Next][%d]: \'%s\' -> \'%s\'\n", (*node)->id, string, (*node)->data);
    return (*node)->id;
  }
  return false;
}

TNodeID TList2WPrev(const char* string)
{
  if (string == nullptr)
    printf("[TList2W::Prev]: No string specified.\n");
  else
  {
    TNode2W<const char*>** node = list2W.Prev(string);
    if (!node)
      printf("[TList2W::Prev]: \'%s\' **NOT FOUND**\n", string);
    else
      printf("[TList2W::Prev][%d]: \'%s\' <- \'%s\'\n", (*node)->id, (*node)->data, string);
    return (*node)->id;
  }
  return false;
}

bool TList2WWalk()
{
  return list2W.Walk(TList2WWalker);
}

int main(void)
{
  // Phase 1 test: Add
  TList2WAdd("Star Trek: Enterprise");
  TList2WAdd("Star Trek");
  TList2WAdd("Walker, Texas Ranger");
  TList2WAdd("Star Trek: The Next Generation");
  TList2WAdd("Star Trek: Deep Space Nine");
  TList2WAdd("Star Trek: Voyager");
  printf("\n");
  TList2WWalk();
  TList2WChange("Walker, Texas Ranger", "Walker Texas Ranger");
  TList2WPrev("Walker Texas Ranger");
  TList2WNext("Star Trek: Deep Space Nine");

  // Phase 2 test: Remove
  TList2WRemove("Walker Texas Ranger");
  TList2WWalk();
  TList2WNext("Star Trek: Deep Space Nine");
  TList2WFind("Star Trek");
  TList2WFind("Walker Texas Ranger");
  TList2WFind("Star Trek: Voyager");
  TList2WSize();
  printf("\n");
  TList2WPrev("Star Trek: Enterprise");
  TList2WPrev("Star Trek");
  TList2WNext("Star Trek: The Next Generation");
  TList2WNext("Star Trek: Voyager");
  system("PAUSE");
  printf("\n");

  return 0;
}
