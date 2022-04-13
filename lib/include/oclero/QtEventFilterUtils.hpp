#pragma once

#include <QObject>

#include <qcoreevent.h>
#include <qevent.h>

#include <QGestureEvent>
#include <QStateMachine>
#include "qgraphicssceneevent.h"

namespace oclero {

// Default trait (invalid case).
template<QEvent::Type T>
struct QtEventTrait;

// Macro to declare valid cases.
#define DECLARE_EVENT_TYPE(EVENT_TYPE, EVENT_CLASS) \
  template<> \
  struct QtEventTrait<EVENT_TYPE> { \
  public: \
    using Type = EVENT_CLASS; \
  };

/// See QEvent documentation for correspondance between QEvent:Type and QEvent-derived classes.
DECLARE_EVENT_TYPE(QEvent::Type::ActionAdded, QActionEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ActionChanged, QActionEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ActionRemoved, QActionEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ActivationChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ApplicationFontChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ApplicationLayoutDirectionChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ApplicationPaletteChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ApplicationStateChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ApplicationWindowIconChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ChildAdded, QChildEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ChildPolished, QChildEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ChildRemoved, QChildEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Clipboard, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Close, QCloseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::CloseSoftwareInputPanel, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ContentsRectChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ContextMenu, QContextMenuEvent)
DECLARE_EVENT_TYPE(QEvent::Type::CursorChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::DeferredDelete, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::DragEnter, QDragEnterEvent)
DECLARE_EVENT_TYPE(QEvent::Type::DragLeave, QDragLeaveEvent)
DECLARE_EVENT_TYPE(QEvent::Type::DragMove, QDragMoveEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Drop, QDropEvent)
DECLARE_EVENT_TYPE(QEvent::Type::DynamicPropertyChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::EnabledChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Enter, QEvent)
#if defined(QT_KEYPAD_NAVIGATION)
DECLARE_EVENT_TYPE(QEvent::Type::EnterEditFocus, QEvent)
#endif
DECLARE_EVENT_TYPE(QEvent::Type::EnterWhatsThisMode, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Expose, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::FileOpen, QFileOpenEvent)
DECLARE_EVENT_TYPE(QEvent::Type::FocusIn, QFocusEvent)
DECLARE_EVENT_TYPE(QEvent::Type::FocusOut, QFocusEvent)
DECLARE_EVENT_TYPE(QEvent::Type::FocusAboutToChange, QFocusEvent)
DECLARE_EVENT_TYPE(QEvent::Type::FontChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Gesture, QGestureEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GestureOverride, QGestureEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GrabKeyboard, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GrabMouse, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneContextMenu, QGraphicsSceneContextMenuEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneDragEnter, QGraphicsSceneDragDropEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneDragLeave, QGraphicsSceneDragDropEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneDragMove, QGraphicsSceneDragDropEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneDrop, QGraphicsSceneDragDropEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneHelp, QHelpEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneHoverEnter, QGraphicsSceneHoverEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneHoverLeave, QGraphicsSceneHoverEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneHoverMove, QGraphicsSceneHoverEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneMouseDoubleClick, QGraphicsSceneMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneMouseMove, QGraphicsSceneMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneMousePress, QGraphicsSceneMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneMouseRelease, QGraphicsSceneMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneMove, QGraphicsSceneMoveEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneResize, QGraphicsSceneResizeEvent)
DECLARE_EVENT_TYPE(QEvent::Type::GraphicsSceneWheel, QGraphicsSceneResizeEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Hide, QHideEvent)
DECLARE_EVENT_TYPE(QEvent::Type::HideToParent, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::HoverEnter, QHoverEvent)
DECLARE_EVENT_TYPE(QEvent::Type::HoverLeave, QHoverEvent)
DECLARE_EVENT_TYPE(QEvent::Type::HoverMove, QHoverEvent)
DECLARE_EVENT_TYPE(QEvent::Type::IconDrag, QIconDragEvent)
DECLARE_EVENT_TYPE(QEvent::Type::InputMethod, QInputMethodEvent)
DECLARE_EVENT_TYPE(QEvent::Type::InputMethodQuery, QInputMethodQueryEvent)
DECLARE_EVENT_TYPE(QEvent::Type::KeyboardLayoutChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::KeyPress, QKeyEvent)
DECLARE_EVENT_TYPE(QEvent::Type::KeyRelease, QKeyEvent)
DECLARE_EVENT_TYPE(QEvent::Type::LanguageChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::LayoutDirectionChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::LayoutRequest, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Leave, QEvent)
#if defined(QT_KEYPAD_NAVIGATION)
DECLARE_EVENT_TYPE(QEvent::Type::LeaveEditFocus, QEvent)
#endif
DECLARE_EVENT_TYPE(QEvent::Type::LeaveWhatsThisMode, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::LocaleChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::NonClientAreaMouseButtonDblClick, QMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::NonClientAreaMouseButtonPress, QMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::NonClientAreaMouseButtonRelease, QMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::NonClientAreaMouseMove, QMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::MacSizeChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::MetaCall, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ModifiedChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::MouseButtonDblClick, QMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::MouseButtonPress, QMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::MouseButtonRelease, QMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::MouseMove, QMouseEvent)
DECLARE_EVENT_TYPE(QEvent::Type::MouseTrackingChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Move, QMoveEvent)
DECLARE_EVENT_TYPE(QEvent::Type::NativeGesture, QNativeGestureEvent)
DECLARE_EVENT_TYPE(QEvent::Type::OrientationChange, QScreenOrientationChangeEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Paint, QPaintEvent)
DECLARE_EVENT_TYPE(QEvent::Type::PaletteChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ParentAboutToChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ParentChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::PlatformPanel, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::PlatformSurface, QPlatformSurfaceEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Polish, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::PolishRequest, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::QueryWhatsThis, QHelpEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ReadOnlyChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::RequestSoftwareInputPanel, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Resize, QResizeEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ScrollPrepare, QScrollPrepareEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Scroll, QScrollEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Shortcut, QShortcutEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ShortcutOverride, QKeyEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Show, QShowEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ShowToParent, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::SockAct, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::StateMachineSignal, QStateMachine::SignalEvent)
DECLARE_EVENT_TYPE(QEvent::Type::StateMachineWrapped, QStateMachine::WrappedEvent)
DECLARE_EVENT_TYPE(QEvent::Type::StatusTip, QStatusTipEvent)
DECLARE_EVENT_TYPE(QEvent::Type::StyleChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TabletMove, QTabletEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TabletPress, QTabletEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TabletRelease, QTabletEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TabletEnterProximity, QTabletEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TabletLeaveProximity, QTabletEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TabletTrackingChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ThreadChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Timer, QTimerEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ToolBarChange, QTimerEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ToolTip, QHelpEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ToolTipChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TouchBegin, QTouchEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TouchCancel, QTouchEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TouchEnd, QTouchEvent)
DECLARE_EVENT_TYPE(QEvent::Type::TouchUpdate, QTouchEvent)
DECLARE_EVENT_TYPE(QEvent::Type::UngrabKeyboard, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::UngrabMouse, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::UpdateLater, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::UpdateRequest, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WhatsThis, QHelpEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WhatsThisClicked, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::Wheel, QWheelEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WinEventAct, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WindowActivate, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WindowBlocked, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WindowDeactivate, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WindowIconChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WindowStateChange, QWindowStateChangeEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WindowTitleChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WindowUnblocked, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::WinIdChange, QEvent)
DECLARE_EVENT_TYPE(QEvent::Type::ZOrderChange, QEvent)

/// Default templated event filter to make installing event filters easier.
/// Usage: `EventFilter<QEvent::ContextMenu>::install(w, [](QContextMenuEvent* e){...})`
/// T: QEvent::Type to watch.
/// The QEvent-devided will be deduced, if correctly declared beforehand with the macro.
template<QEvent::Type T>
class EventFilter : private QObject {
public:
  using Event = typename QtEventTrait<T>::Type;
  using EventCallback = const std::function<bool(Event*)>;

private:
  EventCallback _eventCallback;

  EventFilter() = delete;

  EventFilter(QObject* parent, const EventCallback& eventCallback)
    : QObject(parent)
    , _eventCallback(eventCallback) {
    assert(parent);
    parent->installEventFilter(this);
  }

protected:
  virtual bool eventFilter(QObject* watchedObject, QEvent* evt) override {
    if (evt->type() == T && _eventCallback) {
      auto* const derivedEvent = static_cast<Event*>(evt);
      return _eventCallback(derivedEvent);
    }

    return QObject::eventFilter(watchedObject, evt);
  }

public:
  /// Will call the callback every time an event of type QEvent::Type happens on watchedObject.
  static EventFilter* install(QObject* watchedObject, const EventCallback& eventCallback) {
    return new EventFilter<T>(watchedObject, eventCallback);
  }
};
} // namespace oclero
