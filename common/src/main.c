/*
 * Copyright 2021 The CFU-Playground Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <console.h>
#include <stdio.h>

#include "tflite.h"
#include "menu.h"
#include "functional_cfu_tests.h"
#include "proj_menu.h"
#include "perf.h"
#include "base.h"

void do_person_detect()
{

  // ONCE_AND_QUIT
  load_zeros();
  puts("Running one inference");
  int8_t person, no_person;
  printf("classifying");
  classify(&person, &no_person);
  printf("Person:    %d\nNot person: %d\n", person, no_person);
  if (person <= -30)
  {
    puts("*** No person found");
  }
  else if (person <= 30)
  {
    puts("*** Image has person like attributes");
  }
  else if (person <= 60)
  {
    puts("*** Might be a person");
  }
  else
  {
    puts("*** PERSON");
  }
  puts("Done");
}

static struct Menu MENU = {
    "CFU Playground",
    "main",
    {
        MENU_ITEM('1', "Person Detection", do_person_detect),
        MENU_ITEM('2', "Functional CFU Tests", do_functional_cfu_tests),
        MENU_ITEM('3', "Project menu", do_proj_menu),
        MENU_ITEM('4', "Performance Counter Tests", do_performance_counter_tests),
        MENU_SENTINEL,
    },
};

int main(void)
{
  init_runtime();
  printf("Hello, %s!\n", "World");

  puts("initTfLite()");
  initTfLite();

  menu_run(&MENU);

  return (0);
}
