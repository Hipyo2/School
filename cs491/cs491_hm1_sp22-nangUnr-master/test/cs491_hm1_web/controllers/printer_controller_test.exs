defmodule Cs491Hm1Web.PrinterControllerTest do
  use Cs491Hm1Web.ConnCase

  import Cs491Hm1.OfficeAssetsFixtures

  @create_attrs %{building: "some building", inventory_code: 42, model: "some model", office_number: 42}
  @update_attrs %{building: "some updated building", inventory_code: 43, model: "some updated model", office_number: 43}
  @invalid_attrs %{building: nil, inventory_code: nil, model: nil, office_number: nil}

  describe "index" do
    test "lists all printer", %{conn: conn} do
      conn = get(conn, Routes.printer_path(conn, :index))
      assert html_response(conn, 200) =~ "Listing Printer"
    end
  end

  describe "new printer" do
    test "renders form", %{conn: conn} do
      conn = get(conn, Routes.printer_path(conn, :new))
      assert html_response(conn, 200) =~ "New Printer"
    end
  end

  describe "create printer" do
    test "redirects to show when data is valid", %{conn: conn} do
      conn = post(conn, Routes.printer_path(conn, :create), printer: @create_attrs)

      assert %{id: id} = redirected_params(conn)
      assert redirected_to(conn) == Routes.printer_path(conn, :show, id)

      conn = get(conn, Routes.printer_path(conn, :show, id))
      assert html_response(conn, 200) =~ "Show Printer"
    end

    test "renders errors when data is invalid", %{conn: conn} do
      conn = post(conn, Routes.printer_path(conn, :create), printer: @invalid_attrs)
      assert html_response(conn, 200) =~ "New Printer"
    end
  end

  describe "edit printer" do
    setup [:create_printer]

    test "renders form for editing chosen printer", %{conn: conn, printer: printer} do
      conn = get(conn, Routes.printer_path(conn, :edit, printer))
      assert html_response(conn, 200) =~ "Edit Printer"
    end
  end

  describe "update printer" do
    setup [:create_printer]

    test "redirects when data is valid", %{conn: conn, printer: printer} do
      conn = put(conn, Routes.printer_path(conn, :update, printer), printer: @update_attrs)
      assert redirected_to(conn) == Routes.printer_path(conn, :show, printer)

      conn = get(conn, Routes.printer_path(conn, :show, printer))
      assert html_response(conn, 200) =~ "some updated building"
    end

    test "renders errors when data is invalid", %{conn: conn, printer: printer} do
      conn = put(conn, Routes.printer_path(conn, :update, printer), printer: @invalid_attrs)
      assert html_response(conn, 200) =~ "Edit Printer"
    end
  end

  describe "delete printer" do
    setup [:create_printer]

    test "deletes chosen printer", %{conn: conn, printer: printer} do
      conn = delete(conn, Routes.printer_path(conn, :delete, printer))
      assert redirected_to(conn) == Routes.printer_path(conn, :index)

      assert_error_sent 404, fn ->
        get(conn, Routes.printer_path(conn, :show, printer))
      end
    end
  end

  defp create_printer(_) do
    printer = printer_fixture()
    %{printer: printer}
  end
end
