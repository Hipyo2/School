defmodule Cs491Hm1.OfficeAssetsTest do
  use Cs491Hm1.DataCase

  alias Cs491Hm1.OfficeAssets

  describe "printer" do
    alias Cs491Hm1.OfficeAssets.Printer

    import Cs491Hm1.OfficeAssetsFixtures

    @invalid_attrs %{building: nil, inventory_code: nil, model: nil, office_number: nil}

    test "list_printer/0 returns all printer" do
      printer = printer_fixture()
      assert OfficeAssets.list_printer() == [printer]
    end

    test "get_printer!/1 returns the printer with given id" do
      printer = printer_fixture()
      assert OfficeAssets.get_printer!(printer.id) == printer
    end

    test "create_printer/1 with valid data creates a printer" do
      valid_attrs = %{building: "some building", inventory_code: 42, model: "some model", office_number: 42}

      assert {:ok, %Printer{} = printer} = OfficeAssets.create_printer(valid_attrs)
      assert printer.building == "some building"
      assert printer.inventory_code == 42
      assert printer.model == "some model"
      assert printer.office_number == 42
    end

    test "create_printer/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = OfficeAssets.create_printer(@invalid_attrs)
    end

    test "update_printer/2 with valid data updates the printer" do
      printer = printer_fixture()
      update_attrs = %{building: "some updated building", inventory_code: 43, model: "some updated model", office_number: 43}

      assert {:ok, %Printer{} = printer} = OfficeAssets.update_printer(printer, update_attrs)
      assert printer.building == "some updated building"
      assert printer.inventory_code == 43
      assert printer.model == "some updated model"
      assert printer.office_number == 43
    end

    test "update_printer/2 with invalid data returns error changeset" do
      printer = printer_fixture()
      assert {:error, %Ecto.Changeset{}} = OfficeAssets.update_printer(printer, @invalid_attrs)
      assert printer == OfficeAssets.get_printer!(printer.id)
    end

    test "delete_printer/1 deletes the printer" do
      printer = printer_fixture()
      assert {:ok, %Printer{}} = OfficeAssets.delete_printer(printer)
      assert_raise Ecto.NoResultsError, fn -> OfficeAssets.get_printer!(printer.id) end
    end

    test "change_printer/1 returns a printer changeset" do
      printer = printer_fixture()
      assert %Ecto.Changeset{} = OfficeAssets.change_printer(printer)
    end
  end

  describe "computer" do
    alias Cs491Hm1.OfficeAssets.Computer

    import Cs491Hm1.OfficeAssetsFixtures

    @invalid_attrs %{brand: nil, operating_systems_version: nil}

    test "list_computer/0 returns all computer" do
      computer = computer_fixture()
      assert OfficeAssets.list_computer() == [computer]
    end

    test "get_computer!/1 returns the computer with given id" do
      computer = computer_fixture()
      assert OfficeAssets.get_computer!(computer.id) == computer
    end

    test "create_computer/1 with valid data creates a computer" do
      valid_attrs = %{brand: "some brand", operating_systems_version: 42}

      assert {:ok, %Computer{} = computer} = OfficeAssets.create_computer(valid_attrs)
      assert computer.brand == "some brand"
      assert computer.operating_systems_version == 42
    end

    test "create_computer/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = OfficeAssets.create_computer(@invalid_attrs)
    end

    test "update_computer/2 with valid data updates the computer" do
      computer = computer_fixture()
      update_attrs = %{brand: "some updated brand", operating_systems_version: 43}

      assert {:ok, %Computer{} = computer} = OfficeAssets.update_computer(computer, update_attrs)
      assert computer.brand == "some updated brand"
      assert computer.operating_systems_version == 43
    end

    test "update_computer/2 with invalid data returns error changeset" do
      computer = computer_fixture()
      assert {:error, %Ecto.Changeset{}} = OfficeAssets.update_computer(computer, @invalid_attrs)
      assert computer == OfficeAssets.get_computer!(computer.id)
    end

    test "delete_computer/1 deletes the computer" do
      computer = computer_fixture()
      assert {:ok, %Computer{}} = OfficeAssets.delete_computer(computer)
      assert_raise Ecto.NoResultsError, fn -> OfficeAssets.get_computer!(computer.id) end
    end

    test "change_computer/1 returns a computer changeset" do
      computer = computer_fixture()
      assert %Ecto.Changeset{} = OfficeAssets.change_computer(computer)
    end
  end
end
