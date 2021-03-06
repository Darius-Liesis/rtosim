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

#ifndef rtosim_ExternalForcesFromX_h
#define rtosim_ExternalForcesFromX_h

#include <string>
#include <vector>
#include "rtosim/ExternalForceData.h"
#include "rtb/concurrency/Queue.h"
#include "rtb/concurrency/Latch.h"
#include "rtosim/queue/MultipleExternalForcesQueue.h"

namespace rtosim {
    class ExternalForcesFromX
    {
    public:

        ExternalForcesFromX(
            MultipleExternalForcesQueue& outputMultipleExternalForcesQueue,
            rtb::Concurrency::Latch& doneWithSubscriptions,
            rtb::Concurrency::Latch& doneWithExecution);
        virtual ~ExternalForcesFromX() {};
        virtual void operator()() = 0;
        void updateExternalForces(const MultipleExternalForcesData& currentExternalForceData, double currentTime);
        void sendEndOfData();
        void doneWithSubscriptions();
        void doneWithExecution();
    private:
        MultipleExternalForcesQueue& outputMultipleExternalForcesQueue_;
        rtb::Concurrency::Latch& doneWithSubscriptions_;
        rtb::Concurrency::Latch& doneWithExecution_;
    };
}
#endif
