describe("helloworld", () => {
    it("returns hey world! Don't die plz", () => {
        var actual = helloWorld();
        expect(actual).toBe("hey world! Don't die plz");
    });
});