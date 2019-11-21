#ifndef _ROS_vision_view_h
#define _ROS_vision_view_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vision
{

  class view : public ros::Msg
  {
    public:
      typedef int64_t _checkpoint_type;
      _checkpoint_type checkpoint;

    view():
      checkpoint(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_checkpoint;
      u_checkpoint.real = this->checkpoint;
      *(outbuffer + offset + 0) = (u_checkpoint.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_checkpoint.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_checkpoint.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_checkpoint.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_checkpoint.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_checkpoint.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_checkpoint.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_checkpoint.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->checkpoint);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_checkpoint;
      u_checkpoint.base = 0;
      u_checkpoint.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_checkpoint.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_checkpoint.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_checkpoint.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_checkpoint.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_checkpoint.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_checkpoint.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_checkpoint.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->checkpoint = u_checkpoint.real;
      offset += sizeof(this->checkpoint);
     return offset;
    }

    const char * getType(){ return "vision/view"; };
    const char * getMD5(){ return "8d5b7d9ec5b2f1f18019dbf18a79d4c9"; };

  };

}
#endif
