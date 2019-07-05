// _PiDL.hpp

#ifndef _PiDL_hpp
#define _PiDL_hpp

#include "PiDL.hpp"

namespace PiDL {
    bool dlInit();
    bool dlGray(Image & image, Gray & gray);
    bool dlFace(Gray & gray, Face & face);
    bool dlShape(Gray &gray, Face &face, Shape &shape);
    bool dlChip(Image &image, Shape &shape, Chip &chip);
    bool dlDesc(Chip &chip, Desc &desc);
    
    bool dlFeat(Image &image, Feat &feat);
 }

#endif // _PiDL_hpp