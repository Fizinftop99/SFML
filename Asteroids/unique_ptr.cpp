#include <memory>

template<typename Derived, typename Base>
std::unique_ptr<Derived> static_unique_ptr_cast(std::unique_ptr<Base>& p)
{
    auto d = static_cast<Derived*>(p.release());//����������� p �� ��������, ������� ������� ���������
    return std::unique_ptr<Derived>(d); //���������� ���������������� ���������
}

template<typename Derived, typename Base>
std::shared_ptr<Derived> dynamic_shared_ptr_cast(std::shared_ptr<Base>& p)
{
    if (Derived* result = dynamic_cast<Derived*>(p.get())) //���� ������ ����������� ������� ������������, ������� ���������
    {
        //p.release(); //����������� p �� ��������
        return std::shared_ptr<Derived>(result); //���������� ���������������� ���������
    }
    return std::shared_ptr<Derived>(nullptr); // ����� ���������� nullptr
}





















/*template<class Parent, class Children>
std::unique_ptr<Children> dynamic_unique_ptr_cast_sp(std::unique_ptr<Parent>&& r) {
    Children* res = dynamic_cast<Parent*>(r.get());
    r.release();
    return std::unique_ptr<Children>(res);
}
*/