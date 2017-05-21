/*
* ipop-project
* Copyright 2016, University of Florida
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#ifndef TINCAN_TUNNEL_H_
#define TINCAN_TUNNEL_H_
#include "tincan_base.h"
#include "virtual_link.h"
namespace tincan
{
class Tunnel :
  public sigslot::has_slots<>
{
public:
  Tunnel();
  virtual ~Tunnel() = default;
  void Transmit(TapFrame & frame);
  void AddVlinkEndpoint(shared_ptr<VirtualLink> vlink);
  void QueryCas(Json::Value & cas_info);
  shared_ptr<VirtualLink> Vlink()
  {
    return vlinks_[preferred_];
  }
  sigslot::signal3<uint8_t *, uint32_t, VirtualLink&> SignalMessageReceived;
private:
  void SetPreferredLink(int link_id);
  array<shared_ptr<VirtualLink>, 2> vlinks_;
  int preferred_;
  uint32_t id_;
};
} //namespace tincan
#endif  // TINCAN_TUNNEL_H_