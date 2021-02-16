#include "list"
#include "iostream"
#include "algorithm"
#include "string"

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void Update(const std::string &msg) = 0;
};

class ISubject
{
public:
    virtual ~ISubject() = default;
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

class Subject : public ISubject
{
private:
    std::list<IObserver *> _observers;
    std::string _msg;

public:
    void Attach(IObserver *observer) override
    {
        _observers.push_back(observer);
    }

    void Detach(IObserver *observer) override
    {
        _observers.remove(observer);
    }

    void Notify() override
    {
        std::cout << "Notifying " << _observers.size() << " observers" << std::endl;
        for_each(_observers.begin(), _observers.end(), [&](IObserver *observer) { observer->Update(_msg); });
    }

    void CreateMessage(std::string msg = "Empty")
    {
        this->_msg = msg;
        Notify();
    }

    void SomeAction() {
        this->_msg = "Change message";
        Notify();
        std::cout << "Something important\n" << std::endl;
    }
};


class Observer : public IObserver {
 public:
  Observer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
    this->number_ = Observer::static_number_;
  }
  virtual ~Observer() {
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
  }

  void Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
  }
  void PrintInfo() {
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
  }

 private:
  std::string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

int Observer::static_number_ = 0;

void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  Observer *observer4;
  Observer *observer5;

  subject->CreateMessage("Hello World! :D");
  observer3->RemoveMeFromTheList();

  subject->CreateMessage("The weather is hot today! :p");
  observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  observer5 = new Observer(*subject);

  subject->CreateMessage("My new car is great! ;)");
  observer5->RemoveMeFromTheList();

  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer5;
  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete subject;
}