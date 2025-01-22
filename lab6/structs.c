#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100

typedef struct {
  char name[20];
  char surname[20];
  uint8_t age;
} Person;

void print_person(Person *p);

int main(int argc, char *argv[]) {

  /* struct Person p1 = {"Lukas", "Kollarovic", 20}; */
  Person p1;
  strcpy(p1.name, "Lukas");
  strcpy(p1.surname, "Kollarovic");
  p1.age = 20;

  print_person(&p1);

  Person people[MAX_PEOPLE];

  return 0;
}

void print_person(Person *p) {
  printf("Person:\n");
  printf("- Name: %s\n", p->name);
  printf("- Surname: %s\n", p->surname);
  printf("- Age: %hhu\n", p->age);
}
