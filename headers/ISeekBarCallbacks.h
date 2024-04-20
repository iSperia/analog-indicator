//
// Created by User on 20.04.2024.
//

#ifndef ISEEKBARCALLBACKS_H
#define ISEEKBARCALLBACKS_H



class ISeekBarCallbacks {
public:
    virtual void onProgressChanged(float progress) = 0;
    virtual ~ISeekBarCallbacks() = default;
};



#endif //ISEEKBARCALLBACKS_H
