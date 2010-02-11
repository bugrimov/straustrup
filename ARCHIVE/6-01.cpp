
// a

i=0;
while (i<max_length)
{
  if (input_line[i] == '?') quest_count++;
  i++;
}

// b

while (*input_line++) //!=0
  if (*input_line == '?')
    quest_count++;
