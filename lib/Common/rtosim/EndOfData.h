/* -------------------------------------------------------------------------- *
 * Copyright (c) 2010-2016 C. Pizzolato, M. Reggiani                          *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License");            *
 * you may not use this file except in compliance with the License.           *
 * You may obtain a copy of the License at:                                   *
 * http://www.apache.org/licenses/LICENSE-2.0                                 *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */

#ifndef rtosim_EndOfData_h
#define rtosim_EndOfData_h

#include <limits>

namespace rtosim{
    namespace EndOfData {

        template<typename Frame>
        Frame get() {

            Frame f;
            f.time = std::numeric_limits<double>::infinity();
            return f;
        }

        template<typename Frame>
        bool isEod(const Frame& f) {

            return (f.time == std::numeric_limits<double>::infinity());
        }
    }
}
#endif