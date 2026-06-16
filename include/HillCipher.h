class HillCipher : public Cipher {
public:
    HillCipher(int a, int b, int c, int d);

    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;

private:
    int matrix_[2][2];

    int determinant() const;
    bool hasInverseMatrix() const;
};