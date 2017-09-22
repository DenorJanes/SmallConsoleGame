#include "GameObject.h"

void fill_row(char* row, int size, char with)
{
	for (int i = 0; i < size; ++i)
		row[i] = with;

}