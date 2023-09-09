namespace scuui{
    class this_event_is_not_supported : public std::logic_error{
    public:
        this_event_is_not_supported(const char* ErrInf) : std::logic_error(ErrInf){}
    };
}
