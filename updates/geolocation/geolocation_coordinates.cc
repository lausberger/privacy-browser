/*
 * Copyright (C) 2013 Google Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "third_party/blink/renderer/modules/geolocation/geolocation_coordinates.h"

// LUCAS
#include <random>
#include <string>

namespace privacy {

    void lat(double* latitude) {
      // random latitude integer
      std::random_device rd1;
      std::mt19937 latgen(rd1());
      std::uniform_int_distribution<> rlat(-90, 90);

      // random digit 
      std::random_device rd2;
      std::mt19937 dgen(rd2());
      std::uniform_int_distribution<> rdigit(0, 9); 

      std::string s = "0.";
      for(int n=0; n<15; n++) { // generate a digit [0,9] and append to a string
        s = s + std::to_string(rdigit(dgen));
      }
      
      double lat = rlat(latgen) + std::stod(s); // double via string and int
      *latitude = lat;
    }

    void lng(double* longitude) {
      // random longitude integer
      std::random_device rd1;
      std::mt19937 lnggen(rd1());
      std::uniform_int_distribution<> rlng(-180, 180);

      // random digit 
      std::random_device rd2;
      std::mt19937 dgen(rd2());
      std::uniform_int_distribution<> rdigit(0, 9); 

      std::string s = "0.";
      for(int n=0; n<15; n++) { // generate a digit [0,9] and append to a string
        s = s + std::to_string(rdigit(dgen));
      }

      double lng = rlng(lnggen) + std::stold(s); // double via string and int
      *longitude = lng;
    }
}

namespace blink {

absl::optional<double> GeolocationCoordinates::altitude() const {
  if (can_provide_altitude_)
    return altitude_;
  return absl::nullopt;
}

absl::optional<double> GeolocationCoordinates::altitudeAccuracy() const {
  if (can_provide_altitude_accuracy_)
    return altitude_accuracy_;
  return absl::nullopt;
}

absl::optional<double> GeolocationCoordinates::heading() const {
  if (can_provide_heading_)
    return heading_;
  return absl::nullopt;
}

absl::optional<double> GeolocationCoordinates::speed() const {
  if (can_provide_speed_)
    return speed_;
  return absl::nullopt;
}

}  // namespace blink
