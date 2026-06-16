class Cipher {
public:
    virtual std::string encrypt(const std::string& text) = 0;
    virtual std::string decrypt(const std::string& text) = 0;

    virtual ~Cipher() = default;
};
