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

#ifndef BASE_H
#define BASE_H
#include <stdint.h>

/** Initializes the runtime. */
void init_runtime();

// Read value from console
// Uses strtol. Can accept values in hex or decimal. Also allows negative
// values.
uint32_t read_val(const char* prompt);

#endif  // !BASE_H
