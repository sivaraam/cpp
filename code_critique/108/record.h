namespace util
{
    class Record {
        public:
              Record(uint64_t id,
                        std::string value = {});
                  std::string to_string() const;

        private:
            uint64_t const id;
            std::string value;
    };

    inline
    std::string to_string(Record const &r)
    {
        return r.to_string();
    }
}
