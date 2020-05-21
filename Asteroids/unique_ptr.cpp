#include <memory>

template<typename Derived, typename Base>
std::unique_ptr<Derived> static_unique_ptr_cast(std::unique_ptr<Base>& p)
{
    auto d = static_cast<Derived*>(p.release());//освобождаем p от владения, создаем обычный указатель
    return std::unique_ptr<Derived>(d); //возвращаем интеллектуальный указатель
}

template<typename Derived, typename Base>
std::shared_ptr<Derived> dynamic_shared_ptr_cast(std::shared_ptr<Base>& p)
{
    if (Derived* result = dynamic_cast<Derived*>(p.get())) //Если объект принадлежит системе наследования, создаем указатель
    {
        //p.release(); //освобождаем p от владения
        return std::shared_ptr<Derived>(result); //возвращаем интеллектуальный указатель
    }
    return std::shared_ptr<Derived>(nullptr); // иначе возвращаем nullptr
}





















/*template<class Parent, class Children>
std::unique_ptr<Children> dynamic_unique_ptr_cast_sp(std::unique_ptr<Parent>&& r) {
    Children* res = dynamic_cast<Parent*>(r.get());
    r.release();
    return std::unique_ptr<Children>(res);
}
*/