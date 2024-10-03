#pragma once

#include "SinglePortModule.h"
#include "GpioLogic.h"

#if defined(EF28_BADGE)

class EF28BadgeModule : public SinglePortModule, private concurrency::OSThread
{
public:
    EF28BadgeModule() : concurrency::OSThread("EF28BadgeModule"),
      SinglePortModule("ef28badge", meshtastic_PortNum_EF28_BADGE)
  {
    setup();
  }

protected:
  // isn't called automatically...
  virtual void setup() override;

  // invoked periodically on the thread
  virtual int32_t runOnce() override;

  virtual bool wantPacket(const meshtastic_MeshPacket *p) override;

  virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;

private:
  void boopupAnimation();
};

extern EF28BadgeModule *ef28BadgeModule;

class EF28BadgeLEDPin : public GpioPin
{
  friend class GpioBinaryTransformer;
  friend class GpioUnaryTransformer;

  public:
    enum PinState { On = true, Off = false, Unset = 2 };

    void set(bool value);
    PinState get() const { return value; }

  private:
    PinState value = PinState::Unset;
    GpioTransformer *dependentPin = NULL;
};

#endif
